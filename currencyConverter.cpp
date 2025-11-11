#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>

using namespace std;

// Write callback used by libcurl. Appends received data to the std::string passed via userdata.
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realSize = size * nmemb; // Calculate real size of incoming data
    string* out = static_cast<string*>(userp); // Cast user pointer to std::string pointer
    out->append(static_cast<char*>(contents), realSize); // Append received data to the string
    return realSize;
}

int main()
{
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Failed to initialize CURL\n"; 
        return 1;
    } 

    string response; // will hold the full response body

    // Configure curl
    curl_easy_setopt(curl, CURLOPT_URL, "https://latest.currency-api.pages.dev/v1/currencies/eur.json"); // target URL 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // follow redirects
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // set write callback
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response); // pass string to write callback

    // Perform the request
    CURLcode res = curl_easy_perform(curl); // Execute the configured request
    if (res != CURLE_OK) { //CURLE_OK is an enumerator within the CURLcode enumeration, representing a success status code with a value of 0. It indicates that a cURL operation completed without errors.
        cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << '\n'; // curl_easy_strerror converts CURLcode to a human-readable string.
        curl_easy_cleanup(curl); // Cleanup before returning
        return 1;
    }

    // Cleanup
    curl_easy_cleanup(curl);

    // At this point `response` contains the fetched data as a single string.

    // Split into lines (std::vector<std::string>)
    vector<string> lines;
    {
        istringstream iss(response);
        string line;
        while (getline(iss, line)) {
            lines.push_back(line);
        }
    }
    // Print the lines
   for(size_t i = 0; i < lines.size(); ++i) {
        cout << (i + 1) << ": " << lines[i] << endl;
    }
    
    char choice;
    do{
        string currency1;
        string currency2;

        cout<<"Which currency do you want to convert? (write in shortened form, ex: 'usd') : ";
        
        cin>>currency1;

        cout<<endl;
        cout<<currency1<<" TO: ";

        cin>>currency2;

        cout<<endl;

        currency1="\"" +currency1 +"\"";
        currency2="\"" + currency2 +"\"";//convert strings to avoid mismatches

        size_t found1;
        size_t found2;
        int matchedLineIndex1 = -1;
        int matchedLineIndex2 = -1;
        for(size_t i=0; i<lines.size(); i++){
            found1=lines[i].find(currency1);//searches for currency1
            if (found1 != string::npos) {
            matchedLineIndex1 = static_cast<int>(i); //matchedLineIndex stores which element of the vector (which line) actually contained your currency string.
                                                    // static_cast<int>(i) → converts from size_t (unsigned) to int (signed) explicitly.
            break; // stop at first match
            }
        }
        for(size_t i=0; i<lines.size(); i++){
            found2=lines[i].find(currency2);//searches for currency2
            if (found2 != string::npos) {
            matchedLineIndex2 = static_cast<int>(i); //matchedLineIndex stores which element of the vector (which line) actually contained your currency string.
                                                    // static_cast<int>(i) → converts from size_t (unsigned) to int (signed) explicitly.
            break; // stop at first match
            }
        }
        regex number_regex(R"([-+]?\d*\.?\d+(?:[eE][-+]?\d+)?)"); //to remove everything from string except numbers
        string currency1Position = lines[matchedLineIndex1]; // take the string where currency1 is located to take float from there
        string currency2Position = lines[matchedLineIndex2];// take the string where currency2 is located to take float from there
        smatch match;

        double num_value11;
        if(regex_search(currency1Position, match, number_regex)){
        string num_str1 = match.str(); //this is the string containing the number
        double num_value1 = stod(num_str1);  // convert string → double
        //cout<<currency1<<" "<<num_value1<<endl;
        num_value11=num_value1;
        }

        double num_value22;
        if(regex_search(currency2Position, match, number_regex)){
        string num_str2 = match.str(); //this is the string containing the number
        double num_value2 = stod(num_str2);  // convert string → double
       // cout<<currency2<<" "<<num_value2<<endl;
        num_value22=num_value2;
        }

        /*
        Now should come algorithm to calculate what does 1 * currency1 = x * currency2
        for example what does 1 usd equals to in yen.
        1 usd = 154.00 yen
        TO BE EXACT THIS WAY OF CALCULATING DOESN'T COMPUTE EXACT VALUES. 
        IT'S SOME POLITICAL THINGS I GUESS
        this algorith should go like this:
        1 eur = 1.15580299 USD
        1 eur = 3.12597393 GEL
        1.15580299 USD = 3.12597393 GEL
        1 USD = 3.12597393 GEL / 1.15580299 = 2.704590624 GEL
        TY nika
        */

        cout<<"1 "<<currency1<<" = "<< num_value22 / num_value11 << " "<<currency2<<endl;
        


        cout<<"Want to continue converting? (y/n): ";
        cin>>choice;
    }while(choice=='y' || choice =='Y');
    return 0;
}

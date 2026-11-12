from random import randint, choice, uniform, sample
""" 1. From the set alfa create new string with 1000000 characters. After
	   split this string by character ‘.’ (dot). Calculate and display:
	   a. the string which after splitting by character ' ' (space)      """
alfa = [ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
         'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
         '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', ':', ';', '!', '?', ' ']

""" 2. Create a new set “newSet” of words from the set, obtained in the preceding example, by splitting the 
       string with the punctuation and space characters. Create a dictionary from the set newSet, where any 
       element of newSet will be used as a key and the number of repetition of this element as a value
       on that key. Calculate and display:
       c) The number of values, which contains two symbols 'a’ and 'd', but 
	      these symbols are not presented side by side;
       e)  The number of unique words that at the same time contains alphabet character and digits.
       
	  (Note. The method isalpha() checks word contains or not only alphabet symbols, and the method isdigit 
	  checks word contains or not only digits).     """


""" 3. Create two set (s1 and s2) and fill them with 1000 unique random
        number from a range [1, 9999]. Calculate and display:
        a. The number of elements in union of sets;
        b. The average value of the elements from intersection of sets;
        c. The sum of squares from the symmetric difference of the sets;
        d. The great value from the average values of the elements of sets s1-s2 and s2-s1 ;  """


""" 6. Create a dictionary from the set newSet, whereas a key will be used digits (0-9). If the word starts with 
       a digit then this word must be inserted in the list which has as key this digit. If a word does not start   
       with a digit, then the word must be inserted to list with key “words”. Calculate and display
       a. The value of the key, in which the maximum number of values represents a number (value which contains only digits);
       b. The value of the key, in which average value of numbers (value which contains only digits) is maximum;
       c. The value of the key, in which the average value of words is maximum (in the calculation must participate 
          the number in their order from a word, that at the same time contains alphabet characters and digits. In
          this calculation does not participate words with only digits). """
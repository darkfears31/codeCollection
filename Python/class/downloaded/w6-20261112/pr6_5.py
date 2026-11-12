# List of Family: 100 record
LNames = ['Abashidze', 'Gigauri', 'Archvadze', 'Akhalaia', 'Badzagua', 'Berianidze', 'Berishvili', 'Gventsadze',
          'Dalakishvili', 'Antidze', 'Giorgadze', 'Gogaladze', 'Gotsiridze', 'Vardidze', 'Zarandia', 'Tadumadze',
          'Labadze', 'Kvaratskhelia', 'Kusradze', 'Kveselava', 'Kapanadze', 'Kasradze', 'Kvinikadze', 'Kopadze',
          'Kankia', 'Kordzaia', 'Mikava', 'Melia', 'Moniava', 'Niauri', 'Latsabidze', 'Mikadze', 'Nemsitsveridze',
          'Maisuradze', 'Matsaberidze', 'Mjavia', 'Machaladze', 'Odisharia', 'Metreveli', 'Neparidze', 'Modebadze',
          'Mosia', 'Mardjanidze', 'Mumladze', 'Nasrashvili', 'Naskidashvili', 'Nozadze', 'Nutsubidze', 'Oniani',
          'Okruashvili', 'Pertia', 'Razmadze', 'Revazashvili', 'Saganelidze', 'Salukvadze', 'Samsonashvili',
          'Samkharadze', 'Saralidze', 'Sartania', 'Sarishvili', 'Simonishvili', 'Skhiladze', 'Khurtsidze',
          'Sikharulidze', 'Tabatadze', 'Patsatsia', 'Pilauri', 'Pukhashvili', 'Kobalia', 'Kipshidze', 'Shainidze',
          'Pipia', 'Shengelia', 'Sherozia', 'Shvelidze', 'Chkheidze', 'Chaduneli', 'Chikvashvili', 'Tskitishvili',
          'Chokoraia', 'Tsaguria', 'Tsertsvadze', 'Tsukhishvili', 'Dzindzibadze', 'Tsereteli', 'Tsiklauri',
          'Chavchanidze', 'Chiradze', 'Chelidze', 'Chanturia', 'Siradze', 'Shonia', 'Khandjaladze', 'Kharazishvili',
          'Kheladze', 'Khvingia', 'Khutsishvili', 'Djanelidze', 'Djandjgava', 'Djakhaia', 'Djokhadze']

# List of Girl names: 40 record
GNames = ['Ana', 'Anuki', 'Barbare', 'Gvantsa', 'Diana', 'Eka', 'Elene', 'Veronika', 'Viktoria', 'Tatia', 'Lamzira',
          'Tea', 'Tekle', 'Tiniko', 'Tamari', 'Izabela', 'Ia', 'Iamze', 'Lia', 'Lika', 'Lana', 'Marika', 'Manana',
          'maia', 'maka', 'mariami', 'nana', 'nani', 'nata', 'nato', 'nino', 'nona', 'oliko', 'ketevani', 'salome',
          'sopiko', 'nia', 'kristine', 'shorena', 'khatia']

# List of Boy names: 40 record
BNames = ['Aleko', 'Alika', 'Amiran', 'Andria', 'Archili', 'Aslani', 'Bachuki', 'Beka', 'Giga', 'Giorgi', 'Daviti',
          'Gigi', 'Goga', 'Data', 'Erekle', 'Temuri', 'Iakob', 'Ilia', 'Irakli', 'Lado', 'Lasha', 'Mikheil',
          'Nika', 'Otari', 'Paata', 'Ramaz', 'Ramini', 'Rati', 'Rauli', 'Revazi', 'Roma', 'Romani', 'Sandro',
          'Saba', 'Sergi', 'Simon', 'Shalva', 'Shota', 'Tsotne', 'Djaba', 'Djemal']

# List of grouped Girl and Boy names: 80 record
FNames = ['Ana', 'Anuki', 'Barbare', 'Gvantsa', 'Diana', 'Eka', 'Elene', 'Veronika', 'Viktoria', 'Tatia', 'Lamzira',
          'Tea', 'Tekle', 'Tiniko', 'Tamari', 'Izabela', 'Ia', 'Iamze', 'Lia', 'Lika', 'Lana', 'Marika', 'Manana',
          'maia', 'maka', 'mariami', 'nana', 'nani', 'nata', 'nato', 'nino', 'nona', 'oliko', 'ketevani', 'salome',
          'sopiko', 'nia', 'kristine', 'shorena', 'khatia', 'Aleko', 'Alika', 'Amiran', 'Andria', 'Archili', 'Tsotne',
          'Aslani', 'Bachuki', 'Beka', 'Giga', 'Giorgi', 'Daviti', 'Gigi', 'Goga', 'Data', 'Erekle', 'Temuri', 'Saba',
          'Iakob', 'Ilia', 'Irakli', 'Lado', 'Lasha', 'Mikheil', 'Nika', 'Otari', 'Paata', 'Ramaz', 'Ramini', 'Rati',
          'Rauli', 'Revazi', 'Roma', 'Romani', 'Sandro', 'Sergi', 'Simon', 'Shalva', 'Shota', 'Djaba', 'Djemal']

# List of Subject names: 10 record
Subject = ['programirebis sapudzvlebi', 'Calculus II', 'Introduction to Physics', 'computer skills',
           'Introduction to Chemistry', 'Introduction to Biology', 'Algorithms I', 'Introduction to Electronics',
           'Data structures', 'Algorithms II']

Point = [str(i) for i in range(101)]  # List of points (range [0, 100])

""" None. The below-shown code generates 100000 value and by using them fill the list "Stud_list". """

import random

ch = random.choice
Stud_recs = [' '.join([ch(LNames), ch(FNames), ch(Subject), ch(Point)]) for i in range(100000)]  # List of students
print(Stud_recs[0])

"""
    Write a class, which takes as a parameter generated string. The class must have: 
      Attributes:
         Last Name, First Name, Sex, the Subject as a dictionary  (pair: name of the subject, 
            current score for the subject), GPA

      Methods:
         Constructor; Destructor; __str__() (which returns information about current student); The method, 
            which returns a list of the subjects chosen by the student; The method, which combines two objects 
            from the current class and returns it as a result. The method must use the following principle:
            a) If the names of the objects do not match, the method does nothing   
            b) If the names of the objects match, then the method combines the list of objects in the object 
               calling method with the list of objects of the parameter object:                  
               1. If no similar record was found for the caller, then a record (subject and grade) should be added
               2. If similar records were found for the caller, then all scores for that subject must be combined 
                  in a new list (for example, if for the subject 'X', we found two record {X: 50} and {X: 85}, 
                  then after combining we must get {X: [50, 85]} )
            The method, which from the list of scores of subject returns final scores (average value) for that 
            subject (for example, if for subject 'X' we have list [50, 85], then after using method we mast get
            {X: int(round((50+85)/2, 0))}). Note, that current method must be used after filling list "Stud_list";
            The method, which calculates and returns GPA as average value of scores from the subject list.

    Note. You can define (but not necessary) additional attributes and methods for simplifying the programming process.

    By using the list "Stud_list" fill the new list with appropriate Student class objects. In the result list,
      all elements must be unique. You must sort this list with GPA value and as a result display information about 
      the first 10 students with a higher value of GPA.    """


class Student:
    def __init__(self, stud):
        self.lname = stud[0]
        self.fname = stud[1]
        self.subj = {' '.join(stud[2:-1]): [int(stud[-1])]}
        self.gpa = 0

    def __del__(self):
        pass

    def __str__(self):
        return f"Last Name: {self.lname}\nFirst Name: {self.fname}\nGPA Score: {self.gpa}\n"

    def subject_list(self):
        return list(self.subj.keys())

    def union(self, other):
        if (self.lname, self.fname) == (other.lname, other.fname):
            key = other.subj.keys()
            key = tuple(key)
            key = key[0]
            if key not in self.subj.keys():
                self.subj[key] = other.subj[key]
            else:
                self.subj[key] += other.subj[key]

    def final_score(self):
        for key, value in self.subj.items():
            self.subj[key] = int(round(sum(value) / len(value), 0))
        return self

    def gpa_score(self):
        self.gpa = round(sum((val := [v for v in self.subj.values()])) / len(val), 2)
        return self

    def first_10(lst, func):
        return sorted(lst, key=func, reverse=True)[:10]


Stud_list = [Student(stud.split()) for stud in Stud_recs]

dct = {}
for stud in Stud_list:
    key = (stud.lname, stud.fname)
    if key not in dct.keys():
        dct[key] = stud
    else:
        dct[key].union(stud)

Stud_list = [stud.final_score() for stud in dct.values()]

Stud_list = [stud.gpa_score() for stud in Stud_list]

for stud in Student.first_10(Stud_list, lambda x: x.gpa):
    print(stud, f"Number of subjects: {len(stud.subject_list())}\n")
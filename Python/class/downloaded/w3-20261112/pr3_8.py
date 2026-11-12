from gzip import FNAME
from random import randint, choice, uniform, sample
from collections import namedtuple
# last names: 100 records
LNames = ['Abashidze', 'Gigauri', 'Archvadze', 'Akhalaia', 'Badzaghua', 'Berianidze', 'Berishvili', 'Gventsadze',
          'Dalakishvili', 'Antidze', 'Giorgadze', 'Gogaladze', 'Gotsiridze', 'Vardidze', 'Zarandia', 'Tadumadze',
          'Labadze', 'Kvaratskhelia', 'Kusradze', 'Kveselava', 'Kapanadze', 'Kasradze', 'Kvinikadze', 'Kopadze',
          'Kankia', 'Kordzaia', 'Mikava', 'Melia', 'Moniava', 'Niauri', 'Latsabidze', 'Mikadze', 'Nemsitsveridze',
          'Maisuradze', 'Matsaberidze', 'MჟAvia', 'Machaladze', 'Odisharia', 'Metreveli', 'Nefaridze', 'Modebadze',
          'Marjanidze', 'Mumladze', 'Nasrashvili',  'Janjghava', 'Mosia', 'Nozadze', 'Nutsubidze', 'Oniani',
          'Okruashvili', 'Pertia', 'Razmadze', 'Revazashvili', 'Saganelidze', 'Jakhaia',  'Salukvadze',
          'Samsonashvili', 'Samkharadze', 'Saralidze', 'Sartania', 'Sarishvili', 'Simonishvili', 'Skhiladze',
          'Khurtsidze', 'Sikharulidze', 'Tabatadze', 'Fatsatsia', 'Filauri', 'Fukhashvili', 'Kobalia', 'Kifshidze',
          'Shainidze', 'Fifia', 'Shengelia', 'Sherozia', 'Shvelidze', 'Chkheidze', 'Chaduneli', 'Chikvashvili',
          'Tskitishvili', 'Chokoraia', 'Tsaguria', 'Tsertsvadze', 'Tsukhishvili', 'Dzindzibadze', 'Tsereteli',
          'Tsiklauri', 'Tchavtchanidze', 'Chiradze', 'Tchelidze', 'Tchanturia', 'Siradze', 'Shonia', 'Khanjaladze',
          'Kharazishvili', 'Kheladze', 'Khvingia', 'Khutsishvili', 'Janelidze', 'Jokhadze']

# print(len(LNames))
# girl names: 40 records
GNames = ['Ana', 'Anuki', 'Barbare', 'Gvantsa', 'Diana', 'Eka', 'Elene', 'Veronika', 'Viktoria', 'Tatia', 'Lamzira',
          'Tea', 'Tekle', 'Tiniko', 'Tamari', 'Izabela', 'Ia', 'Iamze', 'Lia', 'Lika', 'Lana', 'Marika', 'Manana',
          'Maia', 'Maka', 'Mariami', 'Nana', 'Nani', 'Nata', 'Nato', 'Nino', 'Nona', 'Oliko', 'Ketevani', 'Salome',
          'Sofiko', 'Nia', 'Kristine', 'Shorena', 'Khatia']

# print(len(GNames))
# boy names: 40 records
BNames = ['Aleko', 'Alika', 'Amiran', 'Andria', 'Archili', 'Aslani', 'Bachuki', 'Beka', 'Giga', 'Giorgi', 'Daviti',
          'Gigi', 'Goga', 'Data', 'Erekle', 'Temuri', 'Iakob', 'Ilia', 'Irakli', 'Lado', 'Lasha', 'Mikheil',
          'Nika', 'Otari', 'Paata', 'Ramaz', 'Ramini', 'Rati', 'Rauli', 'Revazi', 'Roma', 'Romani', 'Sandro',
          'Saba', 'Sergi', 'Simon', 'Shalva', 'Shota', 'Tsotne', 'Jaba']

"""
    Create a list of student records. each entry must include the student's first name, 
    last name and a list of all subjects taken.
    Calculate the GPA for each student and print the higher average student data. 
    if there are more than one such students print all
"""

Student = namedtuple('Student', ['first_name', 'last_name', 'scores'])

students = [ Student(choice(GNames+BNames), choice(LNames), [randint(98, 100) for _ in range(10)])
             for _ in range(1000)]

max_avg = -1

for s in students:
    avg = sum(s.scores) / len(s.scores)/25
    # print(f"student: {s.first_name} {s.last_name}  ==>  average = {avg:.2f}")
    if avg > max_avg:
        max_avg = avg
        best_student = [s]
    elif avg == max_avg:
        best_student.append(s)

if len(best_student) == 1:
    first_name, last_name = best_student[0].first_name, best_student[0].last_name
    print(f"\nBest: {first_name} {last_name} ({max_avg:.2f})")
else:
    print('List of best students: ')
    for first_name, last_name, _ in best_student:
        print(f'\t{first_name} {last_name} ({max_avg:.2f})')


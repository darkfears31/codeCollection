from random import choice
from collections import defaultdict
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


deps = {
    "HR": "Human Resources",
    "AF": "Accounting and Finance",
    "Op": "Operations",
    "IT": "Information Technology",
    "CS": "Customer Service",
    "LC": "Legal and Compliance",
    "RD": "Research and Development",
    "PP": "Procurement / Purchasing",
    "Admin": "Administration"
}


"""
    A list of employees and their departments is provided. Group all employees into
     the appropriate departments using the defaultdict (list).
"""

emp = [(choice(tuple(deps.keys())), f'{choice(LNames)} {choice(GNames + BNames)}') for _ in range(100)]

grp = defaultdict(list)

for dp, name in emp:
    grp[dp].append(name)

for dp, staff in grp.items():
    staff.sort()
    print(f"Department: {deps[dp]} ({len(staff)}) person\n\t{'\n\t'.join(staff)}")
    print()
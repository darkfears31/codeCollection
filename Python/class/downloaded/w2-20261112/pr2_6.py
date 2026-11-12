import re
""" The text below contains certain information. Find the entries that start with
    the word ‘Sensor’ and use the split() method to split the entries into parts. """

text = """
2026-09-28 08:16:12 INFO cache_3 request=GET /items code=200 time=9ms
Order A-1042: item=monitor; qty=2; price=189.50 USD; status=paid.
Contact: Cora+team@sample.net; role=editor; active=yes
Contact: d@x.io; role=guest; active=no
Order B-7: item=keyboard; qty=12; price=49 USD; status=pending.
report_2026-09-28.csv size=2048
Order C-2024: item=mouse_pad; qty=3; price=14.00 USD; status=paid.
2026-09-28 08:15:02 INFO api-01 request=GET /health code=200 time=12ms
Sensor A1: temp=21.5C humidity=45% pressure=1012hPa
backup-2025-12-01.tar.gz size=100000
photo_17.PNG size=512
Sensor B22: temp=-3.0C humidity=81% pressure=998hPa
notes-final.txt size=86
Contact: bob_27@work-mail.org; role=viewer; active=no
Contact: invalid@@example.com; role=admin; active=yes
report_2026-02-30.csv size=0
archive_2026-09-28.zip size=8192
Sensor D4: temp=?.?C humidity=0% pressure=bad
Sensor E55: temp=18.25C humidity=52% pressure=1018hPa
Order X-99999: item=USB-C cable; qty=0; price=9.99 USD; status=failed.
2026-09-28 08:15:07 WARN db-02 request=POST /login code=429 time=850ms
bad-date ERROR api-01 code=500 time=?ms
Note: Order D-0500 has no item data.
Contact: alice.smith@example.com; role=editor; active=yes
Sensor C3: temp=29C humidity=100% pressure=1005hPa
2026-09-28 08:16:11 ERROR api-01 request=GET /users/42 code=503 time=1200ms
"""
for line in text.split('\n'):
    if line.startswith('Sensor'):
        print(re.split(' ', line))

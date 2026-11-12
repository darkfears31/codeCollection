from random import randint as ri, choice as ch, uniform as uf, shuffle
import string
digs = tuple(str(i) for i in list(range(10)))
upper = string.ascii_uppercase
def gen_dig(b1, b2, lst=digs, nozero=True):
    dig_count = ri(b1, b2)
    dig_first = ch(digs[1::]) if nozero else '0'
    res = ''.join([dig_first] + [ch(lst) for _ in range(1, dig_count)])
    return res if len(res) > 1 else (
        f'0{res[0]}' if len(res) == 1 else ''.join([ch(lst[1:]) for _ in range(1, dig_count+1)]))

def gen_date(a = '/-:'):
    sp, mo = ch(a), ri(1, 12)
    dd = ri(1, 28) if mo < 10  else ri(1, 30)
    return (f"{ri(2000, 2026)}{sp}"
            f"{('0' if mo < 10 else '') + str(mo)}{sp}"
            f"{('0' if dd < 10 else '') + str(dd)}")

def gen_time():
    hour = ('0' if ((h := ri(0, 23)) < 10) else '') + str(h)
    minute = ('0' if ((m := ri(0, 59)) < 10) else '') + str(m)
    second = ('0' if ((s := ri(0, 59)) < 10) else '') + str(s)
    return f"{hour}:{minute}:{second}"

def gen_uplett(lett=upper, co=3):
    return ''.join(ch(lett) for _ in range(ri(1, co)))

item_com = ("monitor", "keyboard", "USB-C", "cable", "CPU", "case", "VGA", "mouse-pad")
pp = ('health', 'login', f'users/{ri(1, 1000)}', 'item')
bc = ("report", "backup", "photo", "notes", "file", "archive")
bct = ("csv", "tar.gz", "zip", "txt", "PNG", "conf", "in")
ls5 = ("steel bolt", "copper pipe", "blue paint", "cable tie", "safety glove",)

if __name__ == '__main__':
    res = []
    for _ in range(20000): # გენერირდება 120_000 (=20_000 * 6) ჩანაწერი
        s1 = (f'Order {gen_uplett(co=1)}-{gen_dig(1, 6, digs)}: item={ch(item_com)};'
              f'  qty={gen_dig(1, 3, digs)}; price={uf(0,1000):.2f} USD;'
              f' status={ch(("paid", "pending", "failed") )}.')
    
        s2 = (f"{gen_date()} {gen_time()} {ch(('INFO', 'WARN', 'ERROR'))} "
              f"{ch(('api-01', 'db-02', 'cache-03', 'mem-04'))} "
              f"request={ch(('GET', 'POST'))} "
              f"/{ch(pp)} code={ri(1, 1024)} time={ri(1, 5000)}ms")
    
        s3 = (f"Sensor {gen_uplett()}-{gen_dig(1, 4, nozero=ri(0,1))}: "
              f"temp={uf(-25, 100):.2f} "
              f"humidity={ri(1, 100)}% pressure={ri(500, 1500)}hPa")
    
        s4 = f"Data: {ch(bc)}_{gen_date('-')}.{ch(bct)} size={ri(0, 1_000_000)} (Bytes)"
    
        s5 = (f"SKU: {gen_uplett()}-{gen_dig(1, 6, digs)} | name: {ch(ls5)} | stock: {gen_dig(1, 3, digs, nozero=False)}"
              f" | aisle: {gen_uplett()}-{gen_dig(1, 6, digs)}")
        s6 = (f"TXN#{gen_dig(4, 6)} user=nick_{ch([gen_dig(1, 4, nozero=False)])}"
              f" amount={round(uf(0, 10000),2)}USD card=\'{3*'**** '}{''.join((ch(digs) for _ in range(4)))}\' "
              f"result={ch(('FAIL', 'OK', 'HOLD'))}")
        res += [s1, s2, s3, s4, s5, s6]
    
    shuffle(res)
    shuffle(res)
    res = '\n'.join(res)
    with open(r're_data.in', 'w') as f:
        f.write(res)

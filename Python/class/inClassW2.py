co, wo= 100, ''
for word in sent.split():
    if (a:=len(word)) < co:
        co=len(word)
        wo = word
    elif a == co:
        wo+=' '+word

print(f'word length: {co}')

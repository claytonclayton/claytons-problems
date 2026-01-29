
input()
s = input().split(' ')

pack = []
cur = ''
for w in s:
    if w == 'of':
        pack.append(cur)
        cur = ''
    else:
        cur += ' ' + w
pack.append(cur)

if len(pack) == 1:
    print(pack[0][1:])
    exit()

pack = [i.strip() for i in pack]
pack = [i[4:] if i[:4].lower() == 'the ' else i for i in pack]
pack.reverse()
pack = [i + "'s" for i in pack]
pack = ' '.join(pack)
pack = pack[:-2]

print(pack)

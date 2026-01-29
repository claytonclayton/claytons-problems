input()
s = input().split('of')
s = [i.strip() for i in s]
s = [i[4:] if i[:3] == "the" or i[:3] == "The" else i for i in s]  
s.reverse() 
s = [f"{i}'s" for i in s]
s = ' '.join(s)
s = s[:-2]
print(s)

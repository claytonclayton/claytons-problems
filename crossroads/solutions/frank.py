# Taking inputs
N = int(input())

common  = "."*((N-1)//2) + "#" + "."*((N-1)//2)

for _ in range(int(N//2)):
    print(common)

# Printing middle row
print("#"*N)

for _ in range(int(N//2)):
    print(common)

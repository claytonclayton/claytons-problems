input()
inp = input().split(" of ")
if len(inp) == 1:
    print(inp[0])
    exit()
inp = [x.strip().removeprefix("the ").removeprefix("The ") for x in inp]
print("'s ".join(reversed(inp)))
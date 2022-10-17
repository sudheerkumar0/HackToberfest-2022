rows = int(input("Enter total number of rows: "))
c = 0

for i in range(1, rows+1):
    for space in range(1, (rows-i)+1):
        print(end="  ")
   
    while c!=(2*i-1):
        print("* ", end="")
        c += 1
   
    c = 0
    print()

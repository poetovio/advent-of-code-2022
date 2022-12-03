file = open("input.txt", "r")

datoteka = open("input.txt", "r").read()

vrstice = datoteka.split("\n")

stevec = 0
stevec2 = 0

for vrstica in file:
    prviDel, drugiDel = vrstica[: len(vrstica) // 2], vrstica[len(vrstica) // 2 :]

    for char in prviDel:
        if(drugiDel.find(char) >= 0):
            if(char.isupper()):
                stevec += (ord(char) - 38)
            else:
                stevec += (ord(char) - 96)
            break

for i in range(0, len(vrstice), 3):
    prviDel, drugiDel, tretjiDel = vrstice[i], vrstice[i + 1], vrstice[i + 2]

    for char in prviDel:
        if((drugiDel.find(char) >= 0) and (tretjiDel.find(char) >= 0)):
            if(char.isupper()):
                stevec2 += (ord(char) - 38)
            else:
                stevec2 += (ord(char) - 96)
            break

print("Del 1 -> " + str(stevec))
print("Del 2 -> " + str(stevec2))
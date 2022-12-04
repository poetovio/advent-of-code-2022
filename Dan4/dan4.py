datoteka = open("input.txt", "r").read()

vrstice = datoteka.split("\n")

stevec = 0
stevec2 = 0

for vrstica in vrstice:
    del1, del2 = vrstica.split(",")

    stevilo1, stevilo2 = del1.split("-")
    stevilo3, stevilo4 = del2.split("-")
    if((int(stevilo1) <= int(stevilo3) and int(stevilo2) >= int(stevilo4)) or (int(stevilo3) <= int(stevilo1) and int(stevilo4) >= int(stevilo2))):
        stevec += 1

    if((int(stevilo2) >= int(stevilo3) and int(stevilo1) <= int(stevilo4))):
        stevec2 += 1
    

print("Del 1 -> " + str(stevec))
print("Del 2 -> " + str(stevec2))

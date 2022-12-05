datoteka = open("input.txt", "r").read()

vrstice = datoteka.split("\n")

stevec = ""

prvaVrstica = []
drugaVrstica = []
tretjaVrstica = []
cetrtaVrstica = []
petaVrstica = []
sestaVrstica = []
sedmaVrstica = []
osmaVrstica = []
devetaVrstica = []

inputi = []

inputi.append(prvaVrstica)
inputi.append(drugaVrstica)
inputi.append(tretjaVrstica)
inputi.append(cetrtaVrstica)
inputi.append(petaVrstica)
inputi.append(sestaVrstica)
inputi.append(sedmaVrstica)
inputi.append(osmaVrstica)
inputi.append(devetaVrstica)

for i in range(0, 8):
    prvaVrstica.append(vrstice[i][1:2])
    tretjaVrstica.append(vrstice[i][9:10])
    sestaVrstica.append(vrstice[i][21:22])

drugaVrstica.append(vrstice[2][5:6])

for i in range(3, 8):
    devetaVrstica.append(vrstice[i][33:34])
    drugaVrstica.append(vrstice[i][5:6])

for i in range(1, 8):
    cetrtaVrstica.append(vrstice[i][13:14])
    sedmaVrstica.append(vrstice[i][25:26])

petaVrstica.append(vrstice[5][17:18])

for i in range(5, 8):
    petaVrstica.append(vrstice[i][17:18])
    osmaVrstica.append(vrstice[i][29:30])

prvaVrstica.reverse()
drugaVrstica.reverse()
tretjaVrstica.reverse()
cetrtaVrstica.reverse()
petaVrstica.reverse()
sestaVrstica.reverse()
sedmaVrstica.reverse()
osmaVrstica.reverse()

for i in range(10, len(vrstice)):
    deli = vrstice[i].split(' ')

    steviloPonovitev = 0

    kos = []

    while (steviloPonovitev < int(deli[1])):
        premaknjeno = inputi[int(deli[3]) - 1][-1]

        kos.append(premaknjeno)
        inputi[int(deli[3]) - 1].pop()

        steviloPonovitev += 1

    kos.reverse()

    for i in range(0, len(kos)):
        inputi[int(deli[5]) - 1].append(kos[i])


for input in inputi:
    stevec += input[-1]

print("Del 2 -> " + stevec)
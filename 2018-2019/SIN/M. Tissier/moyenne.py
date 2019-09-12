def calcul_moyenne(notes):
    #liste = [int(liste) for liste in input().split()]
    liste = [5, 10, 15]
    print(liste)

    #for note in liste:
    #    print(note)
    for note in liste:
        somme = note + note

    print("Somme notes = ", somme)
    longueur = len(liste)
    moyenne = somme / longueur
    print("Moyenne= ", moyenne)

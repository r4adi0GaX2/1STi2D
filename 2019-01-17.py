# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
jdc=0
a=2
âge=int(input("Âge : "))
anc=int(input("Ancienneté (en mois) : "))
cadre=input("Cadre? (oui/non) : ")
if anc>=12 :
    jdc=anc*2
elif jdc==28:
    if cadre=="oui" and âge>=35 and anc>=36:
        jdc=jdc+2
    if âge>=45 and anc>=60 and cadre=="oui":
       jdc=jdc+4
print("Jours de congé : ",jdc)
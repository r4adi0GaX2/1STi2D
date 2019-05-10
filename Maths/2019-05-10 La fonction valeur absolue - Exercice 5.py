#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri May 10 12:17:42 2019

@author: r4adi0GaX2
"""

# Exercice 5
#
#On donne l'argorithme suivant:
#
#Variable       t réel
#Entrée         Entrer t
#Traitement     Si t < 0
#                   Alors t prend la valeur -t
#               Fin Si
#Sortie         Afficher t
#
#1. Expliquer ce que fait cet algorithme.
#
#Cet algorithme donne l'opposé d'un nombre si celui-ci est négatif.
#
#2. Proposer un programme Python qui, pour deux réels a et b entrés par l'opérateur, 
#renvoie une expression de |at+b| sans valeur absolue, et cela suivant les valeurs 
#prises par le réel t.

a=int(input("a="))
b=int(input("b="))

print("|",a,"t+",b,"|")
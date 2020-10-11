#Transcrição de DNA

dna = input("Entre com uma fita de DNA: ").upper()

dna_lista = []

for rna in list(dna):    

    if rna == 'T':
        dna_lista.append('U')
    elif rna != '.':
        dna_lista.append(rna)
        
dna = ''.join(dna_lista)

print(dna)

"""
No DNA temos as bases
T - A
C - G 

no RNA temos que

U - A
C - G 

Então para transformar uma fita de DNA em RNA fazemos
a troca do T pelo U somente
"""
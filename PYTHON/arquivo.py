import numpy as np
import matplotlib.pyplot as plt 


data = np.genfromtxt('tempo_execucao.txt', delimiter=',')

algoritmo = data[:, 0]
tamanho_vetor = data[:, 1]
tempo_execucao = data[:, 2]

tamanho_vetor_bubble = tamanho_vetor[algoritmo == 1]
tempo_execucao_bubble = tempo_execucao[algoritmo == 1]

tamanho_vetor_insertion = tamanho_vetor[algoritmo == 2]
tempo_execucao_insertion = tempo_execucao[algoritmo == 2]

tamanho_vetor_selection = tamanho_vetor[algoritmo == 3]
tempo_execucao_selection = tempo_execucao[algoritmo == 3]

tamanho_vetor_shell = tamanho_vetor[algoritmo == 4]
tempo_execucao_shell = tempo_execucao[algoritmo == 4]

tamanho_vetor_quick = tamanho_vetor[algoritmo == 5]
tempo_execucao_quick = tempo_execucao[algoritmo == 5]

tamanho_vetor_merge = tamanho_vetor[algoritmo == 6]
tempo_execucao_merge = tempo_execucao[algoritmo == 6]

plt.figure(figsize=(10, 6))
plt.plot(tamanho_vetor_bubble, tempo_execucao_bubble, label='Bubble Sort')
plt.plot(tamanho_vetor_insertion, tempo_execucao_insertion, label='Insertion Sort')
plt.plot(tamanho_vetor_selection, tempo_execucao_selection, label='Selection Sort')
plt.plot(tamanho_vetor_shell, tempo_execucao_shell, label='Shell Sort')
plt.plot(tamanho_vetor_quick, tempo_execucao_quick, label='Quick Sort')
plt.plot(tamanho_vetor_merge, tempo_execucao_merge, label='Merge Sort')

plt.title('Tempo de execução dos Algoritmos de Ordenação')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo de execução (ms)')
plt.legend()
plt.grid(True)
plt.show()

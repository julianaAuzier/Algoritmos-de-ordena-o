#include <iostream>
#include <chrono>
#include <locale>
using namespace std;

// listas
// Ordem aleat�ria
int nA_10[] = {34, 65, 70, 18, 55, 19, 67, 12, 36, 26};
int nA_50[] = {19, 59, 16, 47, 67, 24, 58, 31, 80, 60, 32, 42, 70, 96, 92, 94, 91, 73, 34, 63, 14, 19, 70, 33, 24, 69,  8, 69, 45, 33,  8, 90, 12, 76, 17, 18, 45, 25, 72, 23, 24, 76, 79, 18, 40, 56, 64,  9, 31, 96};
int nA_100[] = {28, 61, 55, 70, 83, 45, 63, 81,  9, 98, 20, 93, 70, 72, 98, 80, 98, 25, 27,  4, 95, 52, 88, 12, 36, 17, 47, 32, 99, 84, 85, 68, 92, 20, 64, 43, 41, 32, 20, 33, 95,  6, 97, 16, 17, 16,  9,  9,  7, 34, 63, 75, 12, 44, 18, 31, 59, 48, 40, 71, 46, 95, 24, 39, 60, 25, 65, 10, 71, 80, 35, 40, 27, 16, 32, 49, 43, 94, 59, 95, 22, 28, 44, 26, 40, 75, 76, 24,  8, 90, 83, 58, 67, 94, 81,  7, 93, 92, 35, 11};

//Ordenados - crescente
int nC_10[] = {12, 18, 19, 26, 34, 36, 55, 65, 67, 70};
int nC_50[] = {8, 8, 9, 12, 14, 16, 17, 18, 18, 19, 19, 23, 24, 24, 24, 25, 31, 31, 32, 33, 33, 34, 40, 42, 45, 45, 47, 56, 58, 59, 60, 63, 64, 67, 69, 69, 70, 70, 72, 73, 76, 76, 79, 80, 90, 91, 92, 94, 96, 96};
int nC_100[] = {4, 6, 7, 7, 8, 9, 9, 9, 10, 11, 12, 12, 16, 16, 16, 17, 17, 18, 20, 20, 20, 22, 24, 24, 25, 25, 26, 27, 27, 28, 28, 31, 32, 32, 32, 33, 34, 35, 35, 36, 39, 40, 40, 40, 41, 43, 43, 44, 44, 45, 46, 47, 48, 49, 52, 55, 58, 59, 59, 60, 61, 63, 63, 64, 65, 67, 68, 70, 70, 71, 71, 72, 75, 75, 76, 80, 80, 81, 81, 83, 83, 84, 85, 88, 90, 92, 92, 93, 93, 94, 94, 95, 95, 95, 95, 97, 98, 98, 98, 99};

//Ordenados - decrescente
int nD_10[] = {70, 67, 65, 55, 36, 34, 26, 19, 18, 12};
int nD_50[] = {96, 96, 94, 92, 91, 90, 80, 79, 76, 76, 73, 72, 70, 70, 69, 69, 67, 64, 63, 60, 59, 58, 56, 47, 45, 45, 42, 40, 34, 33, 33, 32, 31, 31, 25, 24, 24, 24, 23, 19, 19, 18, 18, 17, 16, 14, 12, 9, 8, 8};
int nD_100[] = {99, 98, 98, 98, 97, 95, 95, 95, 95, 94, 94, 93, 93, 92, 92, 90, 88, 85, 84, 83, 83, 81, 81, 80, 80, 76, 75, 75, 72, 71, 71, 70, 70, 68, 67, 65, 64, 63, 63, 61, 60, 59, 59, 58, 55, 52, 49, 48, 47, 46, 45, 44, 44, 43, 43, 41, 40, 40, 40, 39, 36, 35, 35, 34, 33, 32, 32, 32, 31, 28, 28, 27, 27, 26, 25, 25, 24, 24, 22, 20, 20, 20, 18, 17, 17, 16, 16, 16, 12, 12, 11, 10, 9, 9, 9, 8, 7, 7, 6, 4};


//////////QUICK/////////
int partition(int arr[], int start, int end){
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	// Dando ao elemento pivo sua posicao correta
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Classificando as partes esquerda e direita do elemento pivo
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int start, int end){
	// caso base
	if (start >= end)
		return;
		
	// particionando o array
	int p = partition(arr, start, end);
	
	// ordena a particao esquerda
	quickSort(arr, start, p - 1);

	// ordena a particao direita
	quickSort(arr, p + 1, end);
}
////////////////////////////////////////////////////////////////////////////////
int main(){
    
    setlocale(LC_ALL, "portuguese");
    cout<<"-------Ordena��o por Quick Sort-------\n";
    
	int n = sizeof(nD_100)/ sizeof(nD_100[0]); // TROCAR

    // Tempo inicial
    auto start = chrono::steady_clock::now();
 
    quickSort(nD_100, 0, n - 1); //TROCAR
    
    //tempo final
    auto end = chrono::steady_clock::now();
 
    cout<<"Array ordenado:\n";
	for (int i = 0; i < n; i++) {
		cout << nD_100[i] << " "; //TROCAR
	}
    
    cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
 
    cout << "Tempo decorrido em microsegundos: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " �s" << endl;
 
    cout << "Tempo decorrido em millisegundos: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
 
    cout << "Tempo decorrido em segundos: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";
 
    return 0;
}

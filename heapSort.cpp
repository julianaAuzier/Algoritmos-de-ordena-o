#include <iostream>
#include <chrono>
#include <locale>
using namespace std;

// listas
// Ordem aleatória
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


////////////////////////////////////////////////////////////////////////////////
void heapify(int arr[], int n, int i){
	int largest = i; // Inicializar maior como raiz
	int l = 2 * i + 1; // filho left = 2*i + 1
	int r = 2 * i + 2; // filho right = 2*i + 2

	// Se o filho esquerdo for maior que o root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Se o filho certo for maior que o maior atÃ© agora
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Se o maior nÃ£o for raiz
	if (largest != i){
		swap(arr[i], arr[largest]);

		// Heap recursivamente a sub-Ã¡rvore
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	// Build heap (reorganizar array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Um por um, extraia um elemento do heap
	for (int i = n - 1; i >= 0; i--){
		// Move raiz atual pra Ãºltima folha
		swap(arr[0], arr[i]);

		// chama max heapify no heap reduzido
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////
int main(){
	
	setlocale(LC_ALL, "portuguese");
    cout<<"-------Ordenação por Heap Sort-------\n";
	
    int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(nA_10) / sizeof(nA_10[0]); //TROCAR

    // Tempo inicial
    auto start = chrono::steady_clock::now();
 
    heapSort(nA_10, n); //TROCAR
    
    //tempo final
    auto end = chrono::steady_clock::now();
 
    cout << "Array ordenado:"<<endl;
	printArray(nA_10, n); //TROCAR
    
    cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
 
    cout << "Tempo decorrido em microsegundos: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
 
    cout << "Tempo decorrido em millisegundos: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
 
    cout << "Tempo decorrido em segundos: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";
 
    return 0;
}

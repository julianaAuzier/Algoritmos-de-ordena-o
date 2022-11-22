#include <iostream>
#include <chrono>
#include <locale>
using namespace std;

// listas
int ordCresc[] = {1,2,3,4,5,6,7,8,9,10};

void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

////////////countingSort//////////////
void countingSort(int input_array[],int s, int r){
	int output_array[s];
	int count_array[r];
	
	// inicializar todos os elementos para 0 na matriz de contagem
	for(int i=0;i<r;i++)
		count_array[i]=0;
		
	// para fazer uma contagem de todos os elementos na matriz de entrada
	for(int i=0;i<s;i++)
		++count_array[input_array[i]];
	
	// contagem cumulativa da matriz de contagem para obter as
	// posi��es de elementos a serem armazenados na matriz de sa�da
	for(int i=1;i<r;i++)
		count_array[i]=count_array[i]+count_array[i-1];
	
	// colocando os elementos do array de entrada no array de sa�a com as
	//  posi��es de modo que o resultado seja um array classificado na ordem ASC
	for(int i=0;i<s;i++)
		output_array[--count_array[input_array[i]]] = input_array[i];
	
	// copiar elementos da matriz de sa�da para a matriz de entrada
	for(int i=0;i<s;i++)
		input_array[i]=output_array[i];
}

////////////////HEAP/////////////////
void heapify(int arr[], int n, int i){
	int largest = i; // Inicializar maior como raiz
	int l = 2 * i + 1; // filho left = 2*i + 1
	int r = 2 * i + 2; // filho right = 2*i + 2

	// Se o filho esquerdo for maior que o root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Se o filho certo for maior que o maior at� agora
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Se o maior n�o for raiz
	if (largest != i){
		swap(arr[i], arr[largest]);

		// Heap recursivamente a sub-�rvore
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	// Build heap (reorganizar array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Um por um, extraia um elemento do heap
	for (int i = n - 1; i >= 0; i--){
		// Move raiz atual pra última folha
		swap(arr[0], arr[i]);

		// chama max heapify no heap reduzido
		heapify(arr, i, 0);
	}
}
/////////MERGE/////////
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //tamanho dos sub-arrays esquerdo e direito
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //preencher sub-arrays esquerdo e direito
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //merge arrays temporários em array real
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //elemento extra no array esquerdo
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //elemento extra no array direito
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      
      // ordena primeiro e segundo elemento
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
//////////QUICK/////////
int partition(int arr[], int start, int end){
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}
	// Dando ao elemento pivô sua posi��o correta
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Classificando as partes esquerda e direita do elemento piv�
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
	
	// ordena a partição esquerda
	quickSort(arr, start, p - 1);

	// ordena a partição direita
	quickSort(arr, p + 1, end);
}
////////////////////////////////////////////////////////////////////////////////
int main(){
	
	setlocale(LC_ALL, "portuguese");
	int size= sizeof(ordCresc) / sizeof(ordCresc[0]); //TROCAR
	int range = 100;
	
    cout<<"-------Ordena��o por Count Sort-------\n";
    auto startCS = chrono::steady_clock::now();
    countingSort(ordCresc,size,range); //TROCAR
    auto endCS = chrono::steady_clock::now();
	cout<<"Array ordenado:"<<endl;
    printArray(ordCresc,10);
    cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(endCS - startCS).count()
        << " ns" << endl;

	cout<<"\n\n-------Ordena��o por Heap Sort-------\n";
 	auto startHS = chrono::steady_clock::now();
 	heapSort(ordCresc, size);
 	auto endHS = chrono::steady_clock::now();
 	cout<<"Array ordenado:"<<endl;
    printArray(ordCresc,10);
    cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(endHS - startHS).count()
        << " ns" << endl;

 	cout<<"\n\n-------Ordena��o por Merge Sort-------\n";
 	auto startMS = chrono::steady_clock::now();
 	mergeSort(ordCresc, 0, size-1);
 	auto endMS = chrono::steady_clock::now();
 	cout<<"Array ordenado:"<<endl;
    printArray(ordCresc,10);
 	cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(endMS - startMS).count()
        << " ns" << endl;
        
 	cout<<"\n\n-------Ordena��o por Quick Sort-------\n";
 	auto startQS = chrono::steady_clock::now();
 	quickSort(ordCresc, 0, size - 1);
 	auto endQS = chrono::steady_clock::now();
 	cout<<"Array ordenado:"<<endl;
    printArray(ordCresc,10);
 	cout << "\nTempo decorrido em nanossegundos: "
        << chrono::duration_cast<chrono::nanoseconds>(endQS - startQS).count()
        << " ns" << endl;
    
    return 0;
}
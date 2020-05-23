#include <iostream>
#include <iomanip>
#include <stdio.h>

#define tamanho 10
using namespace std;


 struct FILA{
    int ini ;
    int fim ;
    int item [tamanho];
} ;
 
//retorna se a fila está vazia ou não
bool filaVazia(FILA p){
    if(p.ini == p.fim) {
        return true;
    } else {
        return false;
    }
}
 
//retorna se a fila está cheia ou não
bool filaCheia(FILA p) {
	int tam = sizeof(p.item)/sizeof(int); //determina o tamanho do vetor
	
    if (p.fim < tam) {
        return false;
    } else {
        return true;
    }
}
 
//adiciona valor na fila
void enfilera(FILA &p, int x){
    p.item[p.fim++] = x;
}
 
//remove valor da fila
int desenfilera(FILA &p){
    return (p.item[p.ini++]) ;
}
 
//mostra os valores armazenados na fila
void mostraFila(FILA p) {
	for (int i = p.ini; i < p.fim; i++) {
		cout << p.item[i] << " ";
	}
	cout << "\n";
}
 
 

//Código para testar a implementação
int main(){
	
	//DECLARAÇÃO DE VARIÁVEIS
	
	int escolhido = 0;
	
	//variáveis do FCFS
	float processos;
	int burst = 0;
	float soma = 0;
	float tempoMedio;
	float vetorTempo[20];
	int burstAntigo;
	
	// variáveis do RR
	int i,j;
	int k=0;
	int process = 0;
	int quantum;
	int temp; 
	int s=0,idle=0,done=0;
	float sum=0;
	
	
    //MENU
	cout<< "Menu Inicial"<<endl;
	cout<<"1 - FCFS"<<endl;
 	cout<<"2 - Round Robin"<<endl;
 	cout<< "3 - Sair"<<endl;
    	
	cin>>escolhido;
	switch(escolhido)
	
	{
		case 1: //FCFS
			
			cout<<"Entre com a quantidade de processos: ( < 10)"<<endl;
			cin>>processos;
			vetorTempo[0] = 0; //instanciando primeira posição do vetor
			
			//criar a fila
			FILA fila; 
    		fila.ini = 0;
   	   	    fila.fim = 0;
			
			cout<<"Entre com o Burst Time de cada um:"<<endl;
			cin>>burst; //entrada dos valores de burst
			
			enfilera(fila,burst); // colocando na fila
			burstAntigo = burst; // colocando o valor inicial em uma variável auxiliar
			
			//inserindo os elementos na fila
			
			for(int i = 1; i < processos; i++)
				{
			 		cin>>burst; // entrando com o valor do seguintes bursts
								
			 		enfilera(fila,burst); // colocando na fila
				
					vetorTempo[i] = burstAntigo + vetorTempo[i-1]; // valores de chegada
					burstAntigo = burst;
				
				

				}
			
	 		for(int i =0; i < processos;i++)
				{
			   		cout<<"Tempo de Chegada: "<<vetorTempo[i]<<endl;
			   		soma;
			   		soma = soma+vetorTempo[i];
				
				
				}
				
			cout<<"Burst Time: "<<endl;
			mostraFila(fila);
			
			cout<<"Tempo de Espera Total: "<<endl;
			cout<< soma << endl;
			
			tempoMedio = soma/processos;
			cout<< "Tempo medio de Espera: "<<endl;
			cout<< fixed<<setprecision(2)<< tempoMedio <<endl;

			break;
		
		case 2:
			
			cout<<"Entre com o numero de processos"<<endl;
			cin>>process;
			
             int a[process][4];
  	 	 	 int b[process][5]; 
  	 	 	 
  	 	 	 cout<<" Entre com o numero do Quantum"<<endl;
  	 	 	 cin>> quantum;
  	 	 	 
  	 	 	 cout<< "Entre com os valores: "<<endl;
  	 	 	 cout<< "Processo | Tempo de Chegada | Burst Time"<<endl;
  	 	 	 
  	 	 	 for(i=0;i<process;i++){
  	  	  	  	  for(j=0;j<3;j++){
               	   	   cin>>a[i][j];
	   	 	 	 	 }
          	  	  a[i][3]=a[i][2];// guardando o tempo total de cada processo em outra celula  
          	  }
			
			i=a[0][1]; // guardando em i a posição da primeira linha segunda coluna
		 
		    // i = variavel auxiliar que vai guardar os valores da ultima vez que o processo entrou para
		    // a execução
			
			while(done!=process){
          	  if(k==process)
               k=0;
 
          	  if(a[k][1]<=i){ // checa se o tempo de chegda do processo é <= i
               	   if(a[k][2]!=0){ //checa se o burst time é diferente de zero
                    	if(a[k][2]>=quantum){ //checa se o burst time é maior que o valor do quantum
                             a[k][2]-=quantum; // subtrai o valor do quantum no burst time
       	 	 	 	 	 	 i+=quantum; // incrementa em i o valor do quantum
                         	 }
                    	else{ // se o burst time é menor que o valor do quantum
                         	 i+=a[k][2]; //incrementa em i o valor do burst time
                         	 a[k][2]=0; // muda o valor do burst time na matriz a para 0
                         	 }
 
                    	if(a[k][2]==0){ //se o valor do burst time na matriz a for igual a zero
                    		// vai ser adicionado na matriz b:
                         	 b[s][0]=a[k][0]; // o numero do processo 
                         	 b[s][1]=a[k][1];// o tempo de chegada do processo
                         	 b[s][2]=i; // o valor de i que é o valor da ultima vez que o processo
                         	 //entrou para execução
                         	 b[s][3]=a[k][3];// o valor do burst time
                         	 b[s][4]=((i-a[k][1])-a[k][3]); // faz a conta do algoritmo preemptivo para calcular    
                         	 // o tempo de espera
                         	 sum+=((i-a[k][1])-a[k][3]); // soma o tempo de espera total
                         	 s++;
                         	 done++;
                         	 }
                    	idle=0;
                    	}
               	   	   k++;             
                	}
          	  else{
               	   if(idle==0){
                    	idle=1;
                    	k=0; // zerando o k
                    	}
               	   else if(idle==1){
                     
                    	idle=2;
                    	i++;     
                    	}   
              	    else
                    	i++;           
               	   }
          	  }
				
			cout<<"Processo | Tempo de Chegada | Fim da Execucao | Total Burst| Espera"<<endl;
 
     	 	 for(i=0;i<s;i++)
     	 	 	
          	  	  cout<<b[i][0]<<" | "<<b[i][1]<<" | "<<b[i][2]<<" | "<<b[i][3]<<" | "<<b[i][4]<<endl;	
          	    
          	    
				
			 cout<<"Tempo de Espera Medio: "<<sum/process<<endl<<endl;
			
			
			break;
			
		case 3:
			break;
	}
	
	
    return 0;

	
	
	
	
	
	
}

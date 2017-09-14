#include <stdio.h>


int main(){
	
	int pointEntry [4][2];
	
	short int pointInformation = 1;
	
	bool side[4];
	
	bool checkSide = true;
	
	
	printf("A continuación introduce 4 puntos de coordenadas en el sentido de las agujas del reloj 	para comprobar si la figura es un rectángulo. \n");
	
	
	for(int i = 0; i < 4; i++){
		
		printf("Introduce primero el valor de x y luego el de y correspondiente al punto %hd.",pointInformation);
		
		scanf("%d", &pointEntry[i][0]);
		
		scanf("%d", &pointEntry[i][1]);
		
		pointInformation++;
		
	}
	
	
	side[0] = (pointEntry[0][0] == pointEntry[1][0]) && (pointEntry[0][1] < pointEntry[1][1]);
	
	side[1] = (pointEntry[1][1] == pointEntry[2][1]) && (pointEntry[1][0] < pointEntry[2][0]);
	
	side[2] = (pointEntry[2][0] == pointEntry[3][0]) && (pointEntry[2][1] > pointEntry[3][1]);
	
	side[3] = (pointEntry[3][1] == pointEntry[0][1]) && (pointEntry[3][0] > pointEntry[0][0]);
	
	
	for(int j = 1; j < 5; j++){
		
		if(side[j]){
			
			continue;
			
		}else{
			
			checkSide = false;
			
			break;
			
		}
	}

	
	if(checkSide){
		
		printf("Es un rectangulo. \n");
		
	}else{
		
		printf("No es un rectangulo. \n");
		
	}	
}

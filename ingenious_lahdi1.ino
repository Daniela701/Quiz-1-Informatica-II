/*
  Programa que recibe un numero e imprime la suma de todos sus digitos elevados a ellos mismos;
  para recibir una salida correcta se deben ingresar numeros positivos enteros (solo naturales)
  y menores a 2^16 (teniendo en cuenta que los enteros son de 2 bytes).
*/
/*
 Aclaracion: La libreria math No se utiliza para potenciacion de numeros; solo se hace uso de
 la operacion round para precision numerica al separar los digitos, mas no para otras operaciones. Como se ve en el
 codigo las operaciones de potenciacion solo se hacen con sumas y multiplicaciones.
 */
# include <math.h>
int main(){
  
  init();
  
// SETUP
  //Variables
   float numero, deci=0, num=0;
   int entero=0, suma=0, contador=0, cop=1, mayor=0, veces=1;
  
  Serial.begin(9600);
  
  Serial.print ("Digite un numero N ");//Debe ser un numero natural

  while (Serial.available()==0);
  numero=Serial.parseFloat();
  num=numero;
  Serial.println(numero);
  
    //Ciclo para separar los digitos he irlos elevando asi mismos
    while (numero != 0){
        deci= numero/10;
        entero= deci;
        numero= entero;
        deci -=entero;
        deci *= 10;
        deci= round (deci);
        //Condicional para encontrar el numero mayor entre los digitos
        if (mayor < deci){
            mayor= deci;
        }
        else if (mayor == deci){
            veces++;//Variable que cuenta las veces que aparece el digito mayor
        }
        //Ciclo para elevar el digito a si mismo
         while (contador < deci){
               cop *= deci;
               contador+=1;
            }
        suma += cop; //Aqui se suman los resultados de la potenciacion
        contador = 0;
        cop=1;
    }
  
    //Salida del programa
    Serial.print ("La suma de cada uno de los digitos elevados a si mismos del numero  ");
    Serial.print(num);
    Serial.print (" es: ");
    Serial.print (suma);
    if (veces == 1){
        Serial.print("El digito mayor encontrado es el ");
        Serial.print (mayor);
        Serial.print(" que aparece ");
        Serial.print(veces);
        Serial.print ("vez");
    }
    else{
        Serial.print("El digito mayor encontrado es el ");
        Serial.print (mayor);
        Serial.print(" que aparece ");
        Serial.print(veces);
        Serial.print ("veces");
    }
  
  // FIN SETUP
  while(true){
    // LOOP
    // FIN LOOP
  }
  
  return 0;
}

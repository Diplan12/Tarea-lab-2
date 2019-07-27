#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_e_imprimir_por_nota(struct Estudiante, int n);
void ordenar_por_nombre_o_por_matricula(struct Estudiante, int n);
float promedio_de_un_estudiante(struct Estudiante);
float nota_mayor(struct Estudiante, int n);
float promedio_de_todos_los_estudiantes(struct Estudiante);
int buscar_por_matricula(struct Estudiante, int n);
int buscar_por_nombre(struct Estudiante, int n);




struct Evaluacion
{
    float p1;
    float p2;
    float p3;
};

struct Materia
{
    char * nombre;
    struct Evaluacion * evaluaciones;
};

struct Estudiante
{
    char * nombre;
    int matricula;
    int edad;
    struct Materia * materias;
} * estudiantes;

int dato_matricula;
char dato_nombre;
int main()
{
    char asignaturas; // tipo de variable incorrecto
    int i, n;
    printf("Digite el numero de estudiantes a calificar: ");
    scanf("%d", &n);
    printf("Digite el numero de materias a evaluar : ");
    scanf("%s", &asignaturas);

    estudiantes = (char*)malloc(asignaturas * sizeof(char));
    estudiantes->materias->evaluaciones = (char*)malloc(asignaturas * sizeof(char));

    printf("\nEl promedio de el estudiante es: %f", promedio_de_un_estudiante(estudiantes));

    printf("\n\nEl promedio de todos los estudiantes es: ");
    for(i=0; i<n; i++){
        printf("%.2f\n", promedio_de_todos_los_estudiantes(estudiantes, n));
    }
    if(buscar_por_matricula(estudiantes, n)==i){
      printf("El estudiante matricula [%d] buscado  con todos sus datos esta en la posicion %d", dato_matricula, buscar_por_matricula(estudiantes, n) );
    } else {
        printf("\Matricula Invalida");
    }

    if(buscar_por_nombre(estudiantes, n)==i){
        printf("El estudiante  [%s]  buscado con sus datos esta en la posicion %d", dato_nombre, buscar_por_nombre(estudiantes, n));
    } else {
        printf("\nNo se encuentra este nombre");
    }

    ordenar_por_nombre_o_por_matricula(estudiantes, n);

    ordenar_e_imprimir_por_nota(estudiantes, n);

    printf("La Mayor nota  es: %f", nota_mayor(estudiantes, n));

    free(estudiantes);
    for(i=0; i<n; i++){
        free(estudiantes->materias->nombre);
        free(estudiantes->materias->evaluaciones);
    }
    return 0;
}


float nota_mayor(struct Estudiante, int n){
    int i, mayor=0;
    float nota[]= promedio_de_todos_los_estudiantes(estudiantes, n);
    for(i=0; i<n; i++){
        if(nota[i]>mayor){
            mayor=nota[i];
        }
    }

    return mayor;
}



float promedio_de_un_estudiante(struct Estudiante){
    float promedio;
    printf("Digite el nombre del estudiante: ");
    scanf("%s", (estudiantes+i)->nombre);
    printf("Digite su matricula: ");
    scanf("%s", (estudiantes+i)->matricula);
    printf("Digite su edad: ");
    scanf("%d", (estudiantes+i)->edad);
    printf("Digite la materia: ");
    scanf("s", ((estudiantes+i)->(materias+i))->nombre);
    printf("Digite la nota del primer parcial del estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->p1);
    printf("Digite la nota del segundo parcialdel estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->p2);
    printf("Digite la nota del tercer parcial del estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->p3);
    promedio = (estudiantes->materias->evaluaciones->p1 + estudiantes->materias->evaluaciones->p2 + estudiantes->materias->evaluaciones->p3)/3;
    return promedio;
}



int buscar_por_nombre(struct Estudiante, int n){
    char dato_nombre, i;
    printf("Digite el nombre que desea buscar: ");
    scanf("%s", &dato_nombre);
    for(i=0; i<n; i++){
        if((estudiantes+i)->nombre==dato_nombre){
            return i;
        }
    }
}


float promedio_de_todos_los_estudiantes(struct Estudiante, int n){
    float prom;
    int i;
    for(i=0; i<n; i++){
    printf("Digite el nombre del estudiante: ");
    scanf("%s", (estudiantes+i)->nombre);
    printf("Digite su matricula: ");
    scanf("%s", (estudiantes+i)->matricula);
    printf("Digite su edad: ");
    scanf("%d", (estudiantes+i)->edad);

    printf("Digite la materia: ");
    scanf("s", ((estudiantes+i)->(materias+i))->nombre);
    printf("Digite la nota del primer Parcial del estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->examen1);
    printf("Digite la nota del segundo Parcial del estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->examen2);
    printf("Digite la nota del tercer Parcial del estudiante: ");
    scanf("%f", (((estudiantes+i)->(materias+i))->(evaluaciones+i))->examen3);
    prom = (estudiantes->materias->evaluaciones->examen1 + estudiantes->materias->evaluaciones->examen2 + estudiantes->materias->evaluaciones->examen3)/3;
    return promedio;
    }
}



int buscar_por_matricula(struct Estudiante, int n){
    int dato_matricula, i;
    printf("Digite la matricula: ");
    scanf("%d", &dato);
    for(i=0; i<n; i++){
        if((estudiantes+i)->matricula==dato_matricula){
            return i;
        }
    }
}








void ordenar_por_nombre_o_por_matricula(struct Estudiante, int n){
    int i, j, aux;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if((estudiantes+j)->nombre > (estudiantes+j+1)->nombre){
                aux= (estudiantes+j)->nombre;
                (estudiantes+j)->nombre= (estudiantes+j+1)->nombre;
                (estudiantes+j+1)->nombre= aux;
            }
            if(strcmpi((estudiantes+j)->nombre, (estudiantes+j+1)->nombre)==0){
                if((estudiantes+j)->matricula > (estudiantes+j+1)->matricula){
                    aux= (estudiantes+j)->matricula;
                    (estudiantes+j)->matricula= (estudiantes+j+1)->matricula;
                    (estudiantes+j+1)->matricula= aux;
                }
            }

        }
    }
}


void ordenar_e_imprimir_por_nota(struct Estudiante, int n){
    int aux, i, j;
    float nota[]= promedio_de_todos_los_estudiantes(estudiantes, n); //promedio no retorna arreglo
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(nota[j] > nota[j+1]){
                aux= nota[j];
                nota[j]= nota[j+1];
                nota[j+1]= aux;
            }
        }
    }

    for(i=0; i<n; i++){
        printf("\El nombre es: %s", (estudiantes+i)->nombre);
        printf("\nSu matricula es: %d", (estudiantes+i)->matricula);
        printf("\nSu edad es: %d", (estudiantes+i)->edad);
        printf("\nEl nombre de la materia es: %s", (estudiantes+i)->(Materia+i)->nombre);
        printf("\n Su nota es: %f", nota[i]);

    }
}





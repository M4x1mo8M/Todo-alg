#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "robot.h"

struct _robot {
    struct _codo * codo;
};

struct _codo {
    struct _mano * mano;
    int aceite;
    bool quemado;
};

struct _mano {
    int aceite;
    bool quemado;
};

/**
 * @brief Crea un robot nuevo, con aceite óptimo y sin partes quemadas
 *
 */
robot_t robot_nuevo() {
    robot_t robot;

    robot = malloc(sizeof(struct _robot));

    robot->codo = malloc(sizeof(struct _codo));
    robot->codo->aceite = ACEITE_OPTIMO;
    robot->codo->quemado = false;

    robot->codo->mano = malloc(sizeof(struct _mano));
    robot->codo->mano->aceite = ACEITE_OPTIMO;
    robot->codo->mano->quemado = false;

    return robot;
}

/**
 * @brief Usa el robot, provocando cambios en el aceite y posibles
 * partes quemadas
 *
 */
void usar_robot(robot_t robot,
                 int aceite_codo, bool quemado_codo,
                 int aceite_mano, bool quemado_mano) {
    robot->codo->aceite = aceite_codo;
    robot->codo->quemado = quemado_codo;
    robot->codo->mano->aceite = aceite_mano;
    robot->codo->mano->quemado = quemado_mano;
}

/** 
 * @brief Verifica si el robot tiene el aceite óptimo y ninguna parte quemada.
 *
 */
bool verificar_robot(robot_t robot) {
    bool b1 = robot->codo->aceite == ACEITE_OPTIMO;
    bool b2 = robot->codo->quemado == false;
    bool b3 = robot->codo->mano->aceite == ACEITE_OPTIMO;
    bool b4 = robot->codo->mano->quemado == false;
    return (b1 && b2 && b3 && b4);
}

/**
 * @brief Imprime en pantalla un robot
 *
 */
void mostrar_robot(robot_t robot) {
    printf("    codo              mano\n");
    printf("   aceite            aceite\n");
    printf("     %i                %i\n", robot->codo->aceite, robot->codo->mano->aceite);
    printf("  quemado?          quemado?\n");
    printf("     %i                %i\n", robot->codo->quemado, robot->codo->mano->quemado);
}

/**
 * @brief Repara el robot
 *
 * Reemplaza SOLAMENTE las partes quemadas por partes nuevas con aceite óptimo
 * (requiere liberar memoria y alojar memoria nueva)
 *
 * A las partes no quemadas NO LAS REEMPLAZA, sólo les pone el aceite óptimo
 */
void reparar_robot(robot_t robot) {
    if (!robot->codo->quemado) {
        // Codo sano → lo conservo
        robot->codo->aceite = ACEITE_OPTIMO;

        if (!robot->codo->mano->quemado) {
            robot->codo->mano->aceite = ACEITE_OPTIMO;
        } else {
            free(robot->codo->mano);
            robot->codo->mano = malloc(sizeof(struct _mano));
            robot->codo->mano->aceite = ACEITE_OPTIMO;
            robot->codo->mano->quemado = false;
        }

    } else {
        // 🔥 Codo quemado → reemplazo el codo, pero puedo conservar la mano
        struct _mano *mano = robot->codo->mano;
        bool mano_quemada = mano->quemado;

        free(robot->codo);

        robot->codo = malloc(sizeof(struct _codo));
        robot->codo->aceite = ACEITE_OPTIMO;
        robot->codo->quemado = false;

        if (!mano_quemada) {
            mano->aceite = ACEITE_OPTIMO;
            robot->codo->mano = mano;
        } else {
            free(mano);
            robot->codo->mano = malloc(sizeof(struct _mano));
            robot->codo->mano->aceite = ACEITE_OPTIMO;
            robot->codo->mano->quemado = false;
        }
    }
}


/**
 * @brief Destruye el robot, liberando toda la memoria
 *
 */
void destruir_robot(robot_t robot) {
    free(robot->codo->mano);
    free(robot->codo);
    free(robot);
}

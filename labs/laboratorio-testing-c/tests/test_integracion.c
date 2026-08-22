#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento: 3 panes + 2 leches, 10%% off]\n");
    Carrito c;
    carrito_init(&c);
    
    /* Agregar Pan ($200, cantidad 3) */
    Producto pan = {"Pan", 200, 3};
    carrito_agregar(&c, pan);
    
    /* Agregar Leche ($350, cantidad 2) */
    Producto leche = {"Leche", 350, 2};
    carrito_agregar(&c, leche);
    
    /* Verificar total sin descuento: 600 + 700 = 1300 */
    ASSERT_IGUAL(1300, carrito_total(&c));
    
    /* Verificar total con 10% de descuento: 1300 * 0.9 = 1170 */
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar: verificar capacidad maxima]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Producto", 100, 1};
    
    /* 1) Llenar el carrito hasta su capacidad maxima (4 productos) */
    for (int i = 0; i < MAX_ITEMS; i++) {
        int resultado = carrito_agregar(&c, p);
        ASSERT_IGUAL(1, resultado);  /* Cada agregado debe ser exitoso */
    }
    
    /* 2) Verificar que el conteo es MAX_ITEMS */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
    
    /* 3) Verificar que intentar agregar uno mas devuelve 0 */
    int resultado_extra = carrito_agregar(&c, p);
    ASSERT_IGUAL(0, resultado_extra);
    
    /* 4) Verificar que el conteo sigue siendo MAX_ITEMS (no cambio) */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}

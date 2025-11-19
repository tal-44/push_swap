# push_swap
push_swap, Escuela 42Madrid

## Descripción
Este proyecto es parte del curriculum de 42 School. El objetivo es ordenar una pila de números enteros utilizando un conjunto limitado de operaciones, con el menor número de movimientos posible.

## Estructura del Proyecto

```
push_swap/
├── includes/          # Archivos de cabecera (.h)
│   └── push_swap.h
├── srcs/             # Archivos fuente (.c)
│   ├── main.c
│   ├── push_operations.c
│   ├── reverse_rotate_operations.c
│   ├── rotate_operations.c
│   ├── stack_utils.c
│   └── swap_operations.c
├── libft/            # Biblioteca personalizada de funciones C
│   ├── Makefile
│   ├── libft.h
│   └── *.c
├── Makefile          # Archivo de compilación
├── .gitignore        # Archivos a ignorar por git
└── author            # Archivo de autor (estándar 42)
```

## Compilación

Para compilar el proyecto:
```bash
make
```

Para limpiar archivos objeto:
```bash
make clean
```

Para limpiar todo (incluido el ejecutable):
```bash
make fclean
```

Para recompilar desde cero:
```bash
make re
```

## Operaciones Disponibles

- **sa** (swap a): Intercambia los dos primeros elementos de la pila a
- **sb** (swap b): Intercambia los dos primeros elementos de la pila b
- **ss**: sa y sb al mismo tiempo
- **pa** (push a): Toma el primer elemento de b y lo pone en a
- **pb** (push b): Toma el primer elemento de a y lo pone en b
- **ra** (rotate a): Desplaza todos los elementos de a una posición hacia arriba
- **rb** (rotate b): Desplaza todos los elementos de b una posición hacia arriba
- **rr**: ra y rb al mismo tiempo
- **rra** (reverse rotate a): Desplaza todos los elementos de a una posición hacia abajo
- **rrb** (reverse rotate b): Desplaza todos los elementos de b una posición hacia abajo
- **rrr**: rra y rrb al mismo tiempo

## Uso

```bash
./push_swap [números a ordenar]
```

## Autor
Ver archivo `author`

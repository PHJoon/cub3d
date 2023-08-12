#include "main.h"

void    key_move_left(t_var *var)
{
    var->posX += (-1 * var->dirX) * MOV_SPEED;
    // var->posY += (var->dirY) * MOV_SPEED;
}

void    key_move_right(t_var *var)
{
    var->posX -= (-1 * var->dirX) * MOV_SPEED;
    // var->posY -= (var->dirY) * MOV_SPEED;
}

void    key_move_forward(t_var *var)
{
    var->posX -= var->dirX * MOV_SPEED;
    // var->posY -= var->dirY * MOV_SPEED;
}

void    key_move_backward(t_var *var)
{
    var->posX += var->dirX * MOV_SPEED;
    // var->posY += var->dirY * MOV_SPEED;
}
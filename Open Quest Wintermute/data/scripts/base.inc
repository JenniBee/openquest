#include "scripts\const.inc"

global Scene;
global Keyboard;
global actor;

method LinearMovement(movingEntity, startX, startY, endX, endY)
{
        var dX = Math.Abs(endX - startX);
        var dY = Math.Abs(endY - startY);
        
        var dirX = 1;
        if (startX > endX)
                dirX = -1;
                
        var dirY = 1;
        if (startY > endY)
                dirY = -1;
        
        dirX = dirX * 5;
        dirY = dirY * 5;
                
        var diff = dirX - dirY;
        
        var posX = startX;
        var posY = startY;
        
        while ((posX != endX) && (posY != endY))
        {
                var dblDiff = 2 * diff;
                
                if (dblDiff > (-1 * dY))
                {
                        diff = diff - dY;
                        posX = posX + dirX;
                }
                
                if (dblDiff < dX)
                {
                        diff = diff + dX;
                        posY = posY + dirY;
                }
                
                movingEntity.X = posX;
                movingEntity.Y = posY;
                
                Sleep(20);
        }
        
        movingEntity.X = endX;
        movingEntity.Y = endY;
}
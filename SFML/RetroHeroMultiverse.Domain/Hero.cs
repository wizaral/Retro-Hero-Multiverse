using System;
using System.Text;
using System.Collections.Generic;

namespace RetroHeroMultiverse.Domain
{
    abstract public class Hero
    {
        public double X { get; protected set; }        // позиция
        public double Y { get; protected set; }        // позиция
        public double Dx { get; protected set; }       // смещение
        public double Dy { get; protected set; }       // смещение
        public int Width { get; protected set; }       // ширина текстуры в пикселях
        public int Height { get; protected set; }      // высота текстуры в пикселях
        // public int Type;       // тип перса (1 из трёх)

        protected bool is_stay;   // true - стоит на земле
        protected bool in_ulti;   // true - герой в ультимейте
        protected bool look_side; // true - left, false - right (направление взгляда)

        public Hero()
        {

        }
        public abstract void Ultimate();
    }
}

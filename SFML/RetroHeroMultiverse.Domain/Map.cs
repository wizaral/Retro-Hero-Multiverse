using System;
using System.Text;
using System.Collections.Generic;

namespace RetroHeroMultiverse.Domain
{
    public class Map
    {
        public byte Width { get; private set; }
        public byte Height { get; private set; }
        public byte[,] Blocks { get; private set; }

        public Map()
        {
            Width = 180;
            Height = 33;

            Blocks = new byte[Height, Width];

        }
    }
}

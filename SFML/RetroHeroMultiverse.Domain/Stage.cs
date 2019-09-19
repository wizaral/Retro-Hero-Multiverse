using System;
using System.Text;
using System.Collections.Generic;

namespace RetroHeroMultiverse.Domain
{
    public class Stage
    {
        private Map map;
        private Hero[] heroes;

        public Stage()
        {
            map = new Map();
            heroes = new Hero[] { new Tiny(), new Sonic(), new Mario() };
        }
    }
}

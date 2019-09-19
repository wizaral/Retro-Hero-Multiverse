using System;

namespace RetroHeroMultiverse
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Start test");
            Game game = new Game();
            
            game.Init();
            game.Menu();
            game.Loop();
            game.Stop();

            Console.WriteLine("Finish test");
            Console.ReadKey();
        }
    }
}

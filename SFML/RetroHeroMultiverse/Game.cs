using System;
using SFML.Audio;
using SFML.Graphics;
using SFML.System;
using SFML.Window;
using System.Text;
using System.Collections.Generic;
using RetroHeroMultiverse.Domain;

namespace RetroHeroMultiverse
{
    public class Game
    {
        RenderWindow win;

        public void Init()
        {
            win = new RenderWindow(new SFML.Window.VideoMode(1920, 1080), "GameWindow");
            win.SetVerticalSyncEnabled(true);
            win.Closed += Win_Closed;
        }
        public void Menu()
        {
        }

        public void Loop()
        {
            while (win.IsOpen)
            {
                win.DispatchEvents();
                win.Clear(Color.Black);
                win.Display();
            }
        }

        public void Stop()
        {
        }

        private void Win_Closed(object sender, EventArgs e)
        {
            Stop();
            win.Close();
        }
    }
}

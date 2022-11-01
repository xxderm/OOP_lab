using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Shapes;
using System.Windows.Media;

namespace WpfApp1
{    
    public abstract class Shape
    {
        public abstract void Draw();
        public abstract bool IsHover(Point point);        
        public abstract string Name();
        protected Point position;
        protected Point Position { get => position; set => position = value; }
        protected Brush color;
        public Brush Color { get => color; set => color = value; }
        private int index;
        public int Index { get => index; protected set => index = value; }
    }

    public class Circle : Shape
    {
        public Circle(Canvas canvas, Point position, int radius)
        {
            this.position = position;
            Radius = radius;
            this.canvas = canvas;

            Ellipse = new Ellipse
            {
                Name = "circle" + canvas.Children.Count.ToString()
            };
            canvas.Children.Add(Ellipse);
            color = Brushes.Red;
            Index = canvas.Children.Count;
        }

        public override void Draw()
        {
            Ellipse.Width = Radius * 2;
            Ellipse.Height = Radius * 2;
            Ellipse.Stroke = color;
            Ellipse.Fill = color;            
            Ellipse.SetValue(Canvas.LeftProperty, position.X);
            Ellipse.SetValue(Canvas.TopProperty, position.Y);
        }

        public override bool IsHover(Point point)
        {
            var circlePos = new Point(position.X + Radius, position.Y + Radius);
            var dist = Point.Subtract(circlePos, point).Length;
            return dist <= Radius;
        }

        public override string Name()
        {
            return Ellipse.Name;
        }

        private Canvas canvas;
        public int Radius { get; set; }
        public Ellipse Ellipse { get; private set; }
    }
}

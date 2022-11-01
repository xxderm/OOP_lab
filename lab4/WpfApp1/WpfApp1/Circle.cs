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
        public void Select(Point point)
        {
            Unselect();
            if (IsHover(point))
                Selected = true;
        }
        public void Unselect()
        {
            Selected = false;
        }
        public abstract void Draw();
        public abstract bool IsHover(Point point);        
        public abstract string Name();
        protected Point position;
        protected Point Position { get => position; set => position = value; }
        public bool Selected { get; private set; } = false;
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
        }

        public override void Draw()
        {
            Ellipse.Width = Radius * 2;
            Ellipse.Height = Radius * 2;
            Ellipse.Stroke = defaultColor;
            Ellipse.Fill = defaultColor;
            if (Selected)
            {
                Ellipse.Stroke = selectColor;
                Ellipse.Fill = selectColor;
            }            
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
        private readonly Brush defaultColor = Brushes.Red;
        private readonly Brush selectColor = Brushes.DarkRed;
        public int Radius { get; set; }
        public Ellipse Ellipse { get; private set; }
    }
}

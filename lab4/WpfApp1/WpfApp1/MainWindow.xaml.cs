using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<Shape> shapes;
        private bool select = false;

        public MainWindow()
        {
            InitializeComponent();
            shapes = new List<Shape>();
            canvas.Focusable = true;
            Loaded += (x, y) => Keyboard.Focus(canvas);
        }

        private Tuple<bool, Shape> GetHover()
        {
            for (int i = shapes.Count - 1; i >= 0; i--)
            {
                if (shapes[i].IsHover(Mouse.GetPosition(canvas)))
                    return new Tuple<bool, Shape>(true, shapes[i]);
            }
            return new Tuple<bool, Shape>(false, null);
        }

        private void UnselectAll()
        {
            foreach (var shape in shapes)
                shape.Unselect();
        }

        private void DrawAll()
        {
            foreach (var shape in shapes)
                shape.Draw();
        }

        private void canvas_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            var pos = e.GetPosition(canvas);
            var hoveredShape = GetHover();
            if (!select)
                UnselectAll();

            if (hoveredShape.Item1)
                hoveredShape.Item2.Select(pos);
            else
            {
                pos.X -= 10;
                pos.Y -= 10;
                shapes.Add(new Circle(canvas, pos, 10));
                shapes.Last().Select(e.GetPosition(canvas));
            }

            DrawAll();
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            label.Content = "";
            var hoveredShape = GetHover();
            if (hoveredShape.Item1)
                label.Content = "Hover " + hoveredShape.Item2.Name();
        }

        private void canvas_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.Key)
            {
                case Key.Delete:
                    for (int i = 0; i < shapes.Count; i++)
                    {
                        if (shapes[i].Selected)
                        {
                            canvas.Children.RemoveAt(i + 1);
                            shapes.RemoveAt(i); 
                        }
                    }
                    break;
                case Key.LeftCtrl:
                    select = true;
                    break;
                default:
                    break;
            }
            DrawAll();
        }

        private void canvas_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.LeftCtrl)
                select = false;
        }
    }
}

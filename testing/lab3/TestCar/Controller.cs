using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarSpace
{
    public class Controller
    {
        private List<Car> m_cars = new List<Car>();
        private List<Car> m_carsBroken = new List<Car>();

        public bool AddCar(Car car)
        {

            int length = m_cars.Count;
            if (!m_cars.Contains(car))
            {
                m_cars.Add(car);
            }
            return ((length + 1) == m_cars.Count && AddCarToBroken(car));
        }

        bool AddCarToBroken(Car car)
        {
            if (car.IsCorrectGearForThisSpeed(car.GetDirection()) == false)
            {
                int length = m_carsBroken.Count;
                if (!m_carsBroken.Contains(car))
                {
                    m_carsBroken.Add(car);
                }
                return (length + 1) == m_carsBroken.Count;
            }
            return true;
        }

        public bool Removecar(Car car)
        {
            int length = m_cars.Count;
            int lengthBroken = m_carsBroken.Count;
            bool rightChangeOfListOfBroken = true;
            if (m_cars.Contains(car))
            {
                m_cars.Remove(car);
            }
            if (m_carsBroken.Contains(car))
            {
                m_carsBroken.Remove(car);
                rightChangeOfListOfBroken = ((lengthBroken - 1) == m_carsBroken.Count);
            }
            return ((length - 1) == m_cars.Count && rightChangeOfListOfBroken == true);
        }

        public bool FixCar(Car car)
        {
            int lengthBroken = m_carsBroken.Count;
            if (m_carsBroken.Contains(car))
            {
                car.SetCorrectGear();
                m_carsBroken.Remove(car);
            }
            return ((lengthBroken-1) == m_carsBroken.Count && car.IsCorrectGearForThisSpeed(car.GetDirection()));
        }

        public bool FixAllCars()
        {
            bool isCorrectWork = true;
            while(m_carsBroken.Count != 0)
            {
                isCorrectWork = FixCar(m_carsBroken[0]);
            }
            return (m_carsBroken.Count == 0 && isCorrectWork == true);
        }

        public int GetAmount()
        {
            return m_cars.Count;
        }
        public int GetAmountBroken()
        {
            return m_carsBroken.Count;
        }
        public List<Car> Getcars()
        {
            return m_cars;
        }
        public List<Car> GetBrokenCars()
        {
            return m_carsBroken;
        }
    }
}
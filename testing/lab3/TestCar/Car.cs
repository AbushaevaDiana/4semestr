using System;

namespace CarSpace
{
    public enum Gear
    {
        Reverse = -1,
        Neutral = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5
    };
    public enum Direction
    {
        Along,
        Back,
        OnPlace
    };
    public class Car
    {
        private int m_speed;
        private Gear m_gear;
        private string m_number;

        public Car(int speed, Gear gear, string number)
        {
            m_speed = speed;
            m_gear = gear;
            m_number = number;
        }

        (int, int) reverseSpeedLimits = (-20, 0);
        (int, int) oneSpeedLimits = (0, 30);
        (int, int) twoSpeedLimits = (20, 50);
        (int, int) threeSpeedLimits = (30, 60);
        (int, int) fourSpeedLimits = (40, 90);
        (int, int) fiveSpeedLimits = (50, 150);

        bool IsGearInSpeedFrames()
        {
            if (m_gear == Gear.Reverse && m_speed == 0)
            {
                return true;
            }
            if (m_gear == Gear.Neutral)
            {
                return true;
            }
            if (m_gear == Gear.One && m_speed >= oneSpeedLimits.Item1 && m_speed <= oneSpeedLimits.Item2)
            {
                return true;
            }
            if (m_gear == Gear.Two && m_speed >= twoSpeedLimits.Item1 && m_speed <= twoSpeedLimits.Item2)
            {
                return true;
            }
            if (m_gear == Gear.Three && m_speed >= threeSpeedLimits.Item1 && m_speed <= threeSpeedLimits.Item2)
            {
                return true;
            }
            if (m_gear == Gear.Four && m_speed >= fourSpeedLimits.Item1 && m_speed <= fourSpeedLimits.Item2)
            {
                return true;
            }
            if (m_gear == Gear.Five && m_speed >= fiveSpeedLimits.Item1 && m_speed <= fiveSpeedLimits.Item2)
            {
                return true;
            }

            return false;
        }

        public void SetCorrectGear()
        {
            Gear gear = ChooseCorrectGear();
            m_gear = gear;
        }

        Gear ChooseCorrectGear()
        {
            if (m_speed <= 0)
            {
                return Gear.Reverse;
            }
            if (m_speed >= oneSpeedLimits.Item1 && m_speed <= oneSpeedLimits.Item2)
            {
                return Gear.One;
            }
            if (m_speed >= twoSpeedLimits.Item1 && m_speed <= twoSpeedLimits.Item2)
            {
                return Gear.Two;
            }
            if (m_speed >= threeSpeedLimits.Item1 && m_speed <= threeSpeedLimits.Item2)
            {
                return Gear.Three;
            }
            if (m_speed >= fourSpeedLimits.Item1 && m_speed <= fourSpeedLimits.Item2)
            {
                return Gear.Four;
            }
            if (m_speed >= fiveSpeedLimits.Item1 && m_speed <= fiveSpeedLimits.Item2)
            {
                return Gear.Five;
            }
            return Gear.Neutral;
        }

        public Direction GetDirection()
        {
            if (m_speed < 0)
            {
                return Direction.Back;
            }
            if (m_speed > 0)
            {
                return Direction.Along;
            }
            return Direction.OnPlace;
        }

        public bool IsCorrectGearForThisSpeed(Direction direction)
        {
            switch (m_gear)
            {
                case Gear.Neutral:
                    switch (direction)
                    {
                        case Direction.Back:
                            return (m_speed <= 0);
                        case Direction.Along:
                            return (m_speed >= 0);
                        default:
                            return false;
                    }
                case Gear.Reverse:
                    return (m_speed >= reverseSpeedLimits.Item1 && m_speed <= reverseSpeedLimits.Item2);
                default:
                    return (IsGearInSpeedFrames());
            }
        }

        public string ToStr()
        {
            string isCorrectWork = "correct";
            if (IsCorrectGearForThisSpeed(GetDirection()) == false)
            {
                isCorrectWork = "incorrect";
            }
            return $"Car number:  ({m_number})  " +
                    $"Speed: ({m_speed})  " +
                    $"Gear: ({m_gear})  " +
                    $"Direction: {GetDirection()}  " +
                    $"It's work {isCorrectWork}";
        }
    }
}
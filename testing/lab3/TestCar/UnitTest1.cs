using Microsoft.VisualStudio.TestTools.UnitTesting;
using Moq;
using CarSpace;
using System.Collections.Generic;

namespace CarTests
{
    [TestClass]
    public class CarTests
    {
        public Mock<Car> createCarMock(int speed, Gear gear, string number)
        {
            Mock<Car> carMock = new Mock<Car>(speed, gear, number);
            return carMock;
        }

        [TestMethod]
        public void AddCarToEmptyList()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.One, "111111");

            bool result = controller.AddCar(carMock.Object);

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock.Object.ToStr());
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void AddBrokenCarToEmptyList()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.Four, "111111");

            bool result = controller.AddCar(carMock.Object);

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock.Object.ToStr());
        }

        [TestMethod]
        public void AddCarsToController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(15, Gear.Four, "222222");

            bool result1 = controller.AddCar(carMock1.Object);
            bool result2 = controller.AddCar(carMock2.Object);

            Assert.IsTrue(result1);
            Assert.IsTrue(result2);
            Assert.AreEqual(controller.GetAmount(), 2);
            Assert.AreEqual(controller.GetAmountBroken(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
            Assert.AreEqual(controller.Getcars()[1].ToStr(), carMock2.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock2.Object.ToStr());
        }

        [TestMethod]
        public void AddExistingCarToController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.One, "111111");

            bool result1 = controller.AddCar(carMock.Object);
            bool result2 = controller.AddCar(carMock.Object);

            Assert.IsTrue(result1);
            Assert.IsFalse(result2);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock.Object.ToStr());
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void AddExistingBrokenCarToController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.Four, "111111");

            bool result1 = controller.AddCar(carMock.Object);
            bool result2 = controller.AddCar(carMock.Object);

            Assert.IsTrue(result1);
            Assert.IsFalse(result2);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock.Object.ToStr());
            Assert.AreEqual(controller.GetAmountBroken(), 1);
        }

        [TestMethod]
        public void RemovecarFromEmptyController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.One, "111111");
 
            bool result = controller.Removecar(carMock.Object);

            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 0);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void RemoveBrokenCarFromEmptyController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.Four, "111111");

            bool result = controller.Removecar(carMock.Object);

            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 0);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void RemoveCarFromController()
        {   
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(40, Gear.Two, "111111");
   
            controller.AddCar(carMock.Object);
            bool result = controller.Removecar(carMock.Object);
            
            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 0);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void RemoveBrokenCarFromController()
        {
            Controller controller = new Controller();
            Mock<Car> carMock = createCarMock(15, Gear.Four, "111111");

            controller.AddCar(carMock.Object);
            bool result = controller.Removecar(carMock.Object);

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 0);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void RemoveCarFromControllerOfSeveralElements()
        {
            
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Two, "222222");


            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            bool result = controller.Removecar(carMock1.Object);

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock2.Object.ToStr());
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void RemoveBrokenCarFromControllerOfSeveralElements()
        {

            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");


            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            bool result = controller.Removecar(carMock1.Object);

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock2.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock2.Object.ToStr());
        }

        [TestMethod]
        public void RemoveCarFromControllerIfItNotInController()
        {
            
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Two, "222222");


            controller.AddCar(carMock1.Object);
            bool result = controller.Removecar(carMock2.Object);

            
            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
        }
        [TestMethod]
        public void RemoveBrokenCarFromControllerIfItNotInController()
        {

            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");


            controller.AddCar(carMock1.Object);
            bool result = controller.Removecar(carMock2.Object);


            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> fixxedCarMock1 = createCarMock(15, Gear.One, "111111");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixCar(carMock1.Object);
            
            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), fixxedCarMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixBrokenCarIfItNotInController()
        {

            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixCar(carMock2.Object);

            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 1);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
            Assert.AreEqual(controller.GetBrokenCars()[0].ToStr(), carMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixNotBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixCar(carMock1.Object);

            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
        }

        public void FixNotBrokenCarIfItNotInController()
        {

            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(15, Gear.One, "222222");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixCar(carMock2.Object);

            Assert.IsFalse(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixListOfOneBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> fixxedCarMock1 = createCarMock(15, Gear.One, "111111");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixAllCars();

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), fixxedCarMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixListOfOneNotBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");

            controller.AddCar(carMock1.Object);
            bool result = controller.FixAllCars();

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 1);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
        }

        [TestMethod]
        public void FixListOfSeverelBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");
            Mock<Car> fixxedCarMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> fixxedCarMock2 = createCarMock(40, Gear.Two, "222222");

            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            bool result = controller.FixAllCars();

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 2);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), fixxedCarMock1.Object.ToStr());
            Assert.AreEqual(controller.Getcars()[1].ToStr(), fixxedCarMock2.Object.ToStr());
        }

        [TestMethod]
        public void FixListOfSeverelNotBrokenCar()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Two, "222222");

            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            bool result = controller.FixAllCars();

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 2);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
            Assert.AreEqual(controller.Getcars()[0].ToStr(), carMock1.Object.ToStr());
            Assert.AreEqual(controller.Getcars()[1].ToStr(), carMock2.Object.ToStr());
        }

        [TestMethod]
        public void FixEmptyList()
        {
            Controller controller = new Controller();
            bool result = controller.FixAllCars();

            Assert.IsTrue(result);
            Assert.AreEqual(controller.GetAmount(), 0);
            Assert.AreEqual(controller.GetAmountBroken(), 0);
        }

        [TestMethod]
        public void GetAmountFromEmptyController()
        {
            
            Controller controller = new Controller();

            int amount = controller.GetAmount();
            int result = 0;

            Assert.AreEqual(amount, result);
        }

        [TestMethod]
        public void GetAmountBrokenFromEmptyController()
        {

            Controller controller = new Controller();

            int amount = controller.GetAmountBroken();
            int result = 0;

            Assert.AreEqual(amount, result);
        }

        [TestMethod]
        public void GetAmountFromController()
        {
            
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Two, "222222");


            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            int amount = controller.GetAmount();
            int result = 2;

            Assert.AreEqual(amount, result);
        }

        public void GetAmountBrokenFromController()
        {

            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");


            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            int amount = controller.GetAmountBroken();
            int result = 1;

            Assert.AreEqual(amount, result);
        }

        [TestMethod]
        public void GetCarsFromCcontroller()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.One, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Two, "222222");
            Car car1 = new Car(15, Gear.One, "111111");
            Car car2 = new Car(40, Gear.Two, "222222");

            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            List<Car> controllerCars = controller.Getcars();
            List<Car> result = new List<Car>() { car1, car2 };

            Assert.AreEqual(controllerCars[0].ToStr(), result[0].ToStr());
            Assert.AreEqual(controllerCars[1].ToStr(), result[1].ToStr());
        }
        [TestMethod]
        public void GetBrokenCarsFromCcontroller()
        {
            Controller controller = new Controller();
            Mock<Car> carMock1 = createCarMock(15, Gear.Four, "111111");
            Mock<Car> carMock2 = createCarMock(40, Gear.Reverse, "222222");
            Car car1 = new Car(15, Gear.Four, "111111");
            Car car2 = new Car(40, Gear.Reverse, "222222");

            controller.AddCar(carMock1.Object);
            controller.AddCar(carMock2.Object);
            List<Car> controllerCars = controller.GetBrokenCars();
            List<Car> result = new List<Car>() { car1, car2 };

            Assert.AreEqual(controllerCars[0].ToStr(), result[0].ToStr());
            Assert.AreEqual(controllerCars[1].ToStr(), result[1].ToStr());
        }
    }
}
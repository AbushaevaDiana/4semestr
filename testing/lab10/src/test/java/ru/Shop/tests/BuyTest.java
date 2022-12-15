package ru.Shop.tests;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.Cart;
import ru.Shop.metods.MainPage;
import ru.Shop.metods.Login;
import java.util.concurrent.TimeUnit;

public class BuyTest {
    private ChromeDriver driver;
    private MainPage mainPage;
    private Cart cart;
    private Login login;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Добавление товара в корзину и оформление заказа")
    @Parameters({"outputWord", "inputLogin", "password"})
    public void testBuying(String outputWord, String inputLogin, String password){
        final String alertXpath = "//*[@class='alert alert-success']";

        mainPage = new MainPage(driver);
        mainPage
                .openSelect()
                .startLogination();
        login = new Login(driver);
        login
                .setLogin(inputLogin)
                .setPassword(password)
                .clickEnter()
                .goToMainPage();
        mainPage
                .goToProductCard(outputWord)
                .clickAddToCart();
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);
        cart = new Cart(driver);
        cart
                .clickBuyInModalWindow()
                .clickBuy();

        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        WebElement alert = driver.findElement(By.xpath(alertXpath));
        if(alert.isDisplayed()) {
            System.out.println("Успешно оформлен заказ");
        }
        else {
            System.out.println("Тест не пройден");
        }
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}

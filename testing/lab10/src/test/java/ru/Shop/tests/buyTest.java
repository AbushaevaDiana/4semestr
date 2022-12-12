package ru.Shop.tests;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.cart;
import ru.Shop.metods.mainPage;
import ru.Shop.metods.login;
import java.util.concurrent.TimeUnit;

public class buyTest {
    private ChromeDriver driver;
    private mainPage mainPage;
    private cart cart;
    private login login;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Добавление товара в корзину и оформление заказа")
    @Parameters({"inputWord", "inputLogin", "password"})
    public void testAdding(String inputWord, String inputLogin, String password){
        mainPage = new mainPage(driver);
        mainPage
                .openSelect()
                .startLogination();
        login = new login(driver);
        login
                .setLogin(inputLogin)
                .setPassword(password)
                .clickEnter()
                .goToMainPage();
        mainPage
                .goToProductCard(inputWord)
                .clickAddToCart();
        driver.manage().timeouts().implicitlyWait(5, TimeUnit.SECONDS);
        cart = new cart(driver);
        cart
                .clickBuyInModalWindow()
                .clickBuy();

        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        WebElement alert = driver.findElement(By.xpath("//*[@class='alert alert-success']"));
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

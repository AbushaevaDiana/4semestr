package ru.Shop.tests;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import ru.Shop.metods.Login;
import ru.Shop.metods.MainPage;

public class LoginTest {
    private ChromeDriver driver;
    private Login login;
    private MainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Авторизация на сайте")
    @Parameters({"inputLogin", "password"})
    public void testLogination(String inputLogin, String password){
        final String alertXpath = "//*[@class='alert alert-success']";

        mainPage = new MainPage(driver);
        mainPage
                .openSelect()
                .startLogination();
        login = new Login(driver);
        login
                .setLogin(inputLogin)
                .setPassword(password)
                .clickEnter();

        WebElement alert = driver.findElement(By.xpath(alertXpath));
        if(alert.isDisplayed()) {
            System.out.println("Успешный вход");
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

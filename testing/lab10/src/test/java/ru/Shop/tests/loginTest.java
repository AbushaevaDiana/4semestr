package ru.Shop.tests;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import ru.Shop.metods.login;

import java.util.concurrent.TimeUnit;

public class loginTest {
    private ChromeDriver driver;
    private ru.Shop.metods.login login;
    private ru.Shop.metods.mainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Авторизация на форме")
    @Parameters({"inputLogin", "password"})
    public void testLogination(String inputLogin, String password){
        mainPage = new ru.Shop.metods.mainPage(driver);
        mainPage
                .openSelect()
                .startLogination();
        login = new ru.Shop.metods.login(driver);
        login
                .setLogin(inputLogin)
                .setPassword(password)
                .clickEnter();

        WebElement alert = driver.findElement(By.xpath("//*[@class='alert alert-success']"));
        if(alert.isDisplayed()) {
            System.out.println("Успешный вход");
        }
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}

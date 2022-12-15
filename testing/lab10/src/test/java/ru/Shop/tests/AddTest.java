package ru.Shop.tests;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.MainPage;

import java.util.concurrent.TimeUnit;

public class AddTest {
    private ChromeDriver driver;
    private MainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Добавление товара в корзину")
    @Parameters({"outputWord"})
    public void testAdding(String outputWord){
        final String modalXpath = "//*[@id=\"myModalLabel\"]";

        mainPage = new MainPage(driver);
        mainPage
                .goToProductCard(outputWord)
                .clickAddToCart();

        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
        WebElement modal = driver.findElement(By.xpath(modalXpath));
        WebElement a = driver.findElement(By.xpath(outputWord));
        if(modal.isDisplayed() && a.isDisplayed()) {
            System.out.println("Успешное добавление товара");
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
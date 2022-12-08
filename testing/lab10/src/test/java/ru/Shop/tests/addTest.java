package ru.Shop.tests;

import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;

public class addTest {
    private ChromeDriver driver;
    private ru.Shop.metods.mainPage mainPage;
    @BeforeMethod
    public void setUp(){
        System.setProperty("webdriver.chrome.driver", "/home/diana/Documents/tests/chromedriver");
        driver = new ChromeDriver();
        driver.get("http://shop.qatl.ru/");
    }

    @Test(description = "Добавление товара в корзину")
    @Parameters({"inputWord"})
    public void testAdding(String inputWord){

        mainPage = new ru.Shop.metods.mainPage(driver);
        mainPage
                .goToProductCard(inputWord)
                .clickAddToCart();
    }

    public void check(String inputWord) {
        WebElement modal = driver.findElement(By.xpath("//*[@id=\"myModalLabel\"]"));
        WebElement a = driver.findElement(By.xpath("//a[text()='"+inputWord+"']"));
        if(modal.isDisplayed() && a.isDisplayed()) {
            System.out.println("Успешное добавление товара");
        }
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}

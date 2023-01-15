package ru.Shop.tests;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.Assert;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Parameters;
import org.testng.annotations.Test;
import ru.Shop.metods.MainPage;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.time.Duration;
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

        // Добавить нормальные аасерты с message в них
        new WebDriverWait(driver, Duration.ofSeconds(10)).until(ExpectedConditions.visibilityOfElementLocated(By.xpath(outputWord)));
        WebElement linkToTheAddingClock = driver.findElement(By.xpath(outputWord)); // Переименовать
        WebElement modal = driver.findElement(By.xpath(modalXpath));
        Assert.assertTrue(modal.isDisplayed(), "Не отобразилось модальное окно");
        Assert.assertTrue(linkToTheAddingClock.isDisplayed(), "Не отобразились выбранные часы");
    }
    @AfterMethod
    public void closeDriver() {
        System.out.println("test end");
        driver.close();
    }
}
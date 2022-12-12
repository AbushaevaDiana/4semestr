package ru.Shop.metods;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class cart {
    private WebDriver driver;

    public cart(WebDriver driver){
        this.driver = driver;
    }

    public cart clickBuyInModalWindow() {
        WebElement button = driver.findElement(By.xpath("//*[@id=\"cart\"]/div/div/div[3]/a"));
        button.click();
        return this;
    }

    public cart clickBuy() {
        WebElement button = driver.findElement(By.xpath("//button[text()='Оформить']"));
        button.click();
        return this;
    }

}

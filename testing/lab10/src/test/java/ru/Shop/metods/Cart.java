package ru.Shop.metods;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class Cart {
    private WebDriver driver;

    private final String buttonInModalXpath = "//*[@id=\"cart\"]/div/div/div[3]/a";
    private final String buttonBuyXpath = "//button[text()='Оформить']";

    public Cart(WebDriver driver){
        this.driver = driver;
    }

    public Cart clickBuyInModalWindow() {
        WebElement button = driver.findElement(By.xpath(buttonInModalXpath));
        button.click();
        return this;
    }

    public Cart clickBuy() {
        WebElement button = driver.findElement(By.xpath(buttonBuyXpath));
        button.click();
        return this;
    }

}

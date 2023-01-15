package ru.Shop.metods;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class Login  {
    private WebDriver driver;
    private final String setLoginName = "login";
    private final String setPasswordName = "password";
    private final String enterButtonXpath = "//*[@id=\"login\"]/button";
    private final String goToMainPageButtonXpath = "//a[text()='Главная']";

    public Login(WebDriver driver){
        this.driver = driver;
    }

    public Login setLogin(String login) {
        WebElement loginInput = driver.findElement(By.name(setLoginName));
        loginInput.sendKeys(login);
        return this;
    }

    public Login setPassword(String password) {
        WebElement passwordInput = driver.findElement(By.name(setPasswordName));
        passwordInput.sendKeys(password);
        return this;
    }

    public Login clickEnter(){
        WebElement loginButton = driver.findElement(By.xpath(enterButtonXpath));
        loginButton.click();
        return this;
    }

    public Login goToMainPage(){
        WebElement loginButton = driver.findElement(By.xpath(goToMainPageButtonXpath));
        loginButton.click();
        return this;
    }

}
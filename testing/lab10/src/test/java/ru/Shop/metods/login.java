package ru.Shop.metods;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class login  {
    private WebDriver driver;

    public login(WebDriver driver){
        this.driver = driver;
    }

    public login setLogin(String login) {
        WebElement loginInput = driver.findElement(By.name("login"));
        loginInput.sendKeys(login);
        return this;
    }

    public login setPassword(String password) {
        WebElement passwordInput = driver.findElement(By.name("password"));
        passwordInput.sendKeys(password);
        return this;
    }

    public login clickEnter(){
        WebElement loginButton = driver.findElement(By.xpath("//*[@id=\"login\"]/button"));
        loginButton.click();
        return this;
    }

    public login goToMainPage(){
        WebElement loginButton = driver.findElement(By.xpath("//a[text()='Главная']"));
        loginButton.click();
        return this;
    }

}
{include file=olympics/header.tpl}


<h1>This is the index.tpl</h1>
  <b>{$errors}</b>
            {$form_begin}
            <table width="100%">
              <tr>
                <td width="50%">Company</td>
                <td>{$item_company}</td>
              </tr> 
              <tr>
                <td width="50%">Email as login</td>
                <td>{$item_emailadres}</td>
              </tr>  
              <tr>
                <td width="50%">Password</td>
                <td>{$item_passwd}</td>
              </tr>  
                <td>Send</td>
                <td><input type="submit" value="submit"></td>
              </tr>  
            </table>
          {$form_end}


{include file=olympics/footer.tpl}

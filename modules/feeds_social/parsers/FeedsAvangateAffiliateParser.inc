<?php
// $Id

require_once(dirname(__FILE__) .'/../feeds_social.install');

class FeedsAvangateAffiliateParser extends FeedsParser {  

  /**
  * Parses a raw string and populates FeedsImportBatch object from it.
  */
  public function parse(FeedsImportBatch $batch, FeedsSource $source) {

    $parsers = variable_get('feeds_social_parsers', array());

    // Get the file's content.
    $string = $batch->getRaw();

    // Get the file's content.
    $xml = simplexml_load_string($string);

    foreach($xml->Vendors->Vendor as $id_ => $obj_vendor){

       //dpm((string)$obj_vendor->Name, 'Vendor Name:');

       //Process Vendors.
       $Vendor = (string)$obj_vendor->Name;
       $Vendor = trim($Vendor);
       if(!empty($Vendor)){
           $tid_ = _taxonomy_create_term(array('vid' => $parsers['avangate_affiliate']['vocabularies']['Vendor']['id'], 'name' => $Vendor));
       }
       unset($tid_);

       foreach($obj_vendor->Products->Product as $id__ => $obj_product){

           dpm((string)$obj_product->Name, 'Product Name:');

           // Process Categories.
           $Category = (string)$obj_product->Category;
           $arr_Category_tmp = explode('::', $Category);
           if((int)count($arr_Category_tmp)>0){
               foreach($arr_Category_tmp as $Category){
                   $Category = trim($Category);
                   if(empty($Category)){ continue; }
                   $tid_ = _taxonomy_create_term(array('vid' => $parsers['avangate_affiliate']['vocabularies']['Category']['id'], 'name' => $Category, 'parent_id' => $tid_));
                   $arr_Category[$tid_] = $Category;
               }
           }
           unset($tid_);
           //dpm($arr_Category, '$arr_Category');

           // Process Platforms.
           $Platforms = $obj_product->Platforms;
           if((int)count($Platforms->Platform)>0){
              foreach($Platforms->Platform as $Platform){
                $Platform = (string)$Platform;
                $Platform = trim($Platform);
                if(empty($Platform)){ continue; }
                $tid_ = _taxonomy_create_term(array('vid' => $parsers['avangate_affiliate']['vocabularies']['Platforms']['id'], 'name' => $Platform));
                $arr_Platforms[$tid_] = $Platform;
              }
           }
           unset($tid_);
           //dpm($arr_Platforms, '$arr_Platforms');
           //break;



           $items[] = array(
               'ID'                 => (string)$obj_product->ID,
               'Name'               => (string)$obj_product->Name,
               'Version'            => (string)$obj_product->Version,
               'ShortDescription'   => (string)$obj_product->ShortDescription,
               'LongDescription'    => (string)$obj_product->LongDescription,
               'Currency'           => (string)$obj_product->Currency,
               'Price'              => (string)$obj_product->Price,
               'CommissionType'     => (string)$obj_product->CommissionType,
               'Commission'         => (string)$obj_product->Commission,
               'AffiliateBuyLink'   => (string)$obj_product->AffiliateBuyLink,
               'AffiliateTrialLink' => (string)$obj_product->AffiliateTrialLink,
               'Thumbnail'          => (string)$obj_product->Thumbnail,
               'SmallThumbnail'     => (string)$obj_product->SmallThumbnail,
               'PADlink'            => (string)$obj_product->PADlink,
               'Vendor'             => (string)$obj_vendor->Name,
               'Category'           => $arr_Category,
               'Platforms'          => $arr_Platforms,//Platform
               'Vendor'             => $Vendor,
               //'Translations'       => $obj_product->Translations,//Translation
               //'Promotions'         => (string)$obj_product->Promotions,
           );
           unset($arr_Category, $arr_Platforms);
       }
       unset($Vendor);
       //break;
        
    }

    //dpm($items, '$items:');
    
    //return false;

    $batch->setTitle('Test');
    $batch->setItems($items);


  }

  public function getMappingSources() {
    return array(
        'ID' => array(
            'name' => t('ID'),
            'description' => t(''),
      ),
        'Name' => array(
            'name' => t('Name'),
            'description' => t(''),
      ),
        'Version' => array(
            'name' => t('Version'),
            'description' => t(''),
      ),
        'ShortDescription' => array(
            'name' => t('Short Description'),
            'description' => t(''),
      ),
        'LongDescription' => array(
            'name' => t('Long Description'),
            'description' => t(''),
      ),
        'Currency' => array(
            'name' => t('Currency'),
            'description' => t(''),
      ),
        'Price' => array(
            'name' => t('Price'),
            'description' => t(''),
      ),
        'CommissionType' => array(
            'name' => t('Commission Type'),
            'description' => t(''),
      ),
        'Commission' => array(
            'name' => t('Commission'),
            'description' => t(''),
      ),
        'AffiliateBuyLink' => array(
            'name' => t('Affiliate Buy Link'),
            'description' => t(''),
      ),
        'AffiliateTrialLink' => array(
            'name' => t('Affiliate Trial Link'),
            'description' => t(''),
      ),
        'Thumbnail' => array(
            'name' => t('Big Picture'),
            'description' => t(''),
      ),
        'SmallThumbnail' => array(
            'name' => t('Small Thumbnail'),
            'description' => t(''),
      ),
        'PADlink' => array(
            'name' => t('PAD Link'),
            'description' => t(''),
      ),
        'Category' => array(
            'name' => t('Category'),
            'description' => t(''),
      ),
        'Platforms' => array(
            'name' => t('Platforms'),
            'description' => t(''),
      ),
        'Vendor' => array(
            'name' => t('Vendor'),
            'description' => t(''),
      ),
      );
  }

}

?>